#include "String.h"

CString::CString(const char* str) {
	unsigned int uStringSize = static_cast<unsigned int>(strlen(str ? str : ""));
	m_p = new char[uStringSize + 1];
	strcpy_s(static_cast<char*>(m_p), uStringSize + 1, str ? str : "");
}

CString::CString(const CString& str) {
	const char* sSource = static_cast<const char*>(str.m_p);
	unsigned int uStringSize = static_cast<unsigned int>(strlen(sSource));
	m_p = new char[uStringSize + 1];
	strcpy_s(static_cast<char*>(m_p), uStringSize + 1, sSource);
}

CString::~CString() {
	delete[] static_cast<char*>(m_p);
}

bool CString::operator==(const CString& other) const {
	return strcmp(static_cast<const char*>(m_p), static_cast<const char*>(other.m_p)) == 0;
}

bool CString::operator!=(const CString& other) const {
	return !(*this == other);
}

bool CString::operator<(const CString& other) const {
	return strcmp(static_cast<const char*>(m_p), static_cast<const char*>(other.m_p)) < 0;
}

bool CString::operator>(const CString& other) const {
	return strcmp(static_cast<const char*>(m_p), static_cast<const char*>(other.m_p)) > 0;
}

CString CString::operator+(const CString& other) const {
	const char* sString1 = static_cast<const char*>(m_p);
	const char* sString2 = static_cast<const char*>(other.m_p);
	
	unsigned int uStringSize = static_cast<unsigned int>(strlen(sString1) + strlen(sString2));

	char* sBuffer = new char[uStringSize + 1];

	strcpy_s(sBuffer, uStringSize + 1, sString1);
	strcat_s(sBuffer, uStringSize + 1, sString2);

	CString oResult(sBuffer);

	delete[] sBuffer;
	sBuffer = nullptr;

	return oResult;
}

CString CString::operator+(char c) const {
	const char* sString = static_cast<const char*>(m_p);

	unsigned int uStringSize = static_cast<unsigned int>(strlen(sString));

	char* sBuffer = new char[uStringSize + 2];

	strcpy_s(sBuffer, uStringSize + 2, sString);

	sBuffer[uStringSize - 1] = c;
	sBuffer[uStringSize] = '\0';

	CString oResult(sBuffer);

	delete[] sBuffer;
	sBuffer = nullptr;

	return oResult;
}

CString& CString::operator=(const CString& other) {
	if (this != &other) {
		delete[] static_cast<char*>(m_p);

		const char* sSource = static_cast<const char*>(other.m_p);
		unsigned int uStringSize = static_cast<unsigned int>(strlen(sSource));
		m_p = new char[uStringSize + 1];
		strcpy_s(static_cast<char*>(m_p), uStringSize + 1, sSource);
	}

	return *this;
}

CString& CString::operator=(char c) {
	delete[] static_cast<char*>(m_p);

	m_p = new char[2];
	
	static_cast<char*>(m_p)[0] = c;
	static_cast<char*>(m_p)[1] = '\0';
	
	return *this;
}

CString& CString::operator+=(const CString& other) {
	*this = *this + other;
	return *this;
}

CString& CString::operator+=(char c) {
	*this = *this + c;
	return *this;
}

char& CString::operator[](unsigned int pos) {
	return static_cast<char*>(m_p)[pos];
}

const char& CString::operator[](unsigned int pos) const {
	return static_cast<const char*>(m_p)[pos];
}

int CString::Length() const {
	return static_cast<int>(strlen(static_cast<const char*>(m_p)));
}

CString CString::FromInt(int val) {
	char sBuffer[12];
	sprintf_s(sBuffer, "%d", val);
	return CString(sBuffer);
}

CString CString::HexFromInt(int val) {
	char sBuffer[9];
	sprintf_s(sBuffer, "%X", val);
	return CString(sBuffer);
}

CString CString::FromFloat(float val) {
	char sBuffer[32];
	sprintf_s(sBuffer, "%f", val);
	return CString(sBuffer);
}

int CString::ToInt() const {
	return atoi(static_cast<const char*>(m_p));
}

float CString::ToFloat() const {
	return static_cast<float>(atof(static_cast<const char*>(m_p)));
}

const char* CString::ToCString() const {
	return static_cast<const char*>(m_p);
}

CString CString::Left(int n) const {
	if (n >= Length()) return CString(static_cast<const char*>(m_p));
	
	char* sBuffer = new char[n + 1];
	strcpy_s(sBuffer, n + 1, static_cast<const char*>(m_p));
	sBuffer[n] = '\0';

	CString oResult(sBuffer);

	delete[] sBuffer;
	sBuffer = nullptr;

	return oResult;
}

CString CString::Right(int n) const {
	if (n >= Length()) return CString(static_cast<const char*>(m_p));

	return CString(static_cast<const char*>(m_p) + (Length() - n));
}

CString CString::Mid(int ofs, int n) {
	if (ofs > Length()) return CString("");
	if (ofs + n > Length()) return Right(ofs);

	char* sBuffer = new char[n + 1];
	strncpy_s(sBuffer, n + 1, static_cast<const char*>(m_p) + ofs, n);
	sBuffer[n] = '\0';

	CString oResult(sBuffer);

	delete[] sBuffer;
	sBuffer = nullptr;

	return oResult;
}

//CString CString::Replace(const CString& find, const CString& rep) const {
//	if (find.m_p || Find(find, 0) == -1) return *this;
//
//	while (Find(find, 0) != -1) {
//
//
//	}
//
//	char* sBuffer = new char[n + 1];
//	strncpy_s(sBuffer, n + 1, static_cast<const char*>(m_p) + ofs, n);
//	sBuffer[n] = '\0';
//	
//	CString oResult(sBuffer);
//	
//	delete[] sBuffer;
//	sBuffer = nullptr;
//	
//	return oResult;
//}

int CString::Find(const CString& str, int ofs) const {
	if (ofs > str.Length()) return -1;
	if (str.m_p) return -1;

	const char* sFoundString = strstr(static_cast<const char*>(m_p), str.ToCString());
	return sFoundString ? static_cast<int>(sFoundString - static_cast<const char*>(m_p)) : -1;
}

CString CString::ToUpper() const {
	CString sUpper(*this);

	for (int uIndex = 0; uIndex < sUpper.Length(); uIndex++) {
		sUpper[uIndex] = static_cast<char>(toupper(sUpper[uIndex]));
	}

	return sUpper;
}

CString CString::ToLower() const {
	CString sLower(*this);

	for (int uIndex = 0; uIndex < sLower.Length(); uIndex++) {
		sLower[uIndex] = static_cast<char>(tolower(sLower[uIndex]));
	}

	return sLower;
}