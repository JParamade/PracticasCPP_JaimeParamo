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
	
	Map(sUpper, [](char _cChar) -> char { return static_cast<char>(toupper(_cChar)); });

	return sUpper;
}

CString CString::ToLower() const {
	CString sLower(*this);

	Map(sLower, [](char _cChar) -> char { return static_cast<char>(tolower(_cChar)); });

	return sLower;
}

CString CString::LTrim() const {
	const char* pStart = static_cast<const char*>(m_p);
	while (isspace(*pStart)) pStart++;

	return CString(pStart);
}

CString CString::RTrim() const {
	int iStringLength = Length();
	
	while (iStringLength > 0 && isspace(static_cast<const char*>(m_p)[iStringLength - 1])) iStringLength--;

	char* sBuffer = new char[iStringLength + 1];
	strncpy_s(sBuffer, iStringLength + 1, static_cast<const char*>(m_p), iStringLength);
	sBuffer[iStringLength] = '\0';

	CString oResult(sBuffer);

	delete[] sBuffer;
	sBuffer = nullptr;

	return oResult;
}

CString CString::Trim() const {
	return LTrim().RTrim();
}

CString CString::LSet(int len, char c) const {
	if (Length() == len) return *this;
	
	char* sBuffer = new char[len + 1];
	
	if (Length() > len) strcpy_s(sBuffer, len + 1, static_cast<const char*>(m_p) + (Length() - len));
	else {
		unsigned int uPatternSize = len - Length();
		memset(sBuffer, c, uPatternSize);
		strcpy_s(sBuffer + uPatternSize, Length() + 1, static_cast<const char*>(m_p));
	}

	CString oResult(sBuffer);

	delete[] sBuffer;
	sBuffer = nullptr;

	return oResult;
}

CString CString::RSet(int len, char c) const {
	if (Length() == len) return *this;
	
	char* sBuffer = new char[len + 1];
	
	if (Length() > len) strncpy_s(sBuffer, len + 1, static_cast<const char*>(m_p), len);
	else {
		strcpy_s(sBuffer, Length() + 1, static_cast<const char*>(m_p));
		memset(sBuffer + Length(), c, len - Length());
	}
	sBuffer[len] = '\0';

	CString oResult(sBuffer);

	delete[] sBuffer;
	sBuffer = nullptr;

	return oResult;
}

CString CString::StripExt() const {
	const char* pDot = strrchr(static_cast<const char*>(m_p), '.');
	if (!pDot || pDot == static_cast<const char*>(m_p)) return *this;

	unsigned int uStringSize = pDot - static_cast<const char*>(m_p);
	char* sBuffer = new char[uStringSize + 1];
	strncpy_s(sBuffer, uStringSize + 1, static_cast<const char*>(m_p), uStringSize);
	sBuffer[uStringSize] = '\0';

	CString oResult(sBuffer);

	delete[] sBuffer;
	sBuffer = nullptr;

	return oResult;
}

CString CString::StripDir() const {
	const char* pSlash = strrchr(static_cast<const char*>(m_p), '/');
	if (!pSlash) pSlash = strrchr(static_cast<const char*>(m_p), '\\');

	return pSlash ? CString(pSlash + 1) : *this;
}

CString CString::ExtractExt() const {
	const char* pDot = strrchr(static_cast<const char*>(m_p), '.');
	if (!pDot || pDot == static_cast<const char*>(m_p)) return CString("");

	return CString(pDot + 1);
}

CString CString::ExtractDir() const {
	const char* pSlash = strrchr(static_cast<const char*>(m_p), '/');
	if (!pSlash) pSlash = strrchr(static_cast<const char*>(m_p), '\\');
	if (!pSlash) return CString("");

	unsigned int uStringSize = pSlash - static_cast<const char*>(m_p) + 1;
	char* sBuffer = new char[uStringSize + 1];
	strncpy_s(sBuffer, uStringSize + 1, static_cast<const char*>(m_p), uStringSize);
	sBuffer[uStringSize] = '\0';

	CString oResult(sBuffer);

	delete[] sBuffer;
	sBuffer = nullptr;

	return oResult;
}

CString CString::RealPath() const {
	char sBuffer[_MAX_PATH];
	if (_fullpath(sBuffer, static_cast<const char*>(m_p), _MAX_PATH)) return CString(sBuffer);
	
	return *this;
}

CString CString::Read(const CString& filename) {
	FILE* pFile;
	fopen_s(&pFile, filename.ToCString(), "r");
	if (!pFile) return CString("");
	
	fseek(pFile, 0, SEEK_END);
	unsigned int uStringSize = ftell(pFile);
	fseek(pFile, 0, SEEK_SET);

	char* sBuffer = new char[uStringSize + 1];
	fread(sBuffer, sizeof(char), uStringSize, pFile);
	sBuffer[uStringSize] = '\0';

	fclose(pFile);

	CString oResult(sBuffer);

	delete[] sBuffer;
	sBuffer = nullptr;

	return oResult;
}

void CString::Write(const CString& filename, bool append) const {
	FILE* pFile;
	fopen_s(&pFile, filename.ToCString(), append ? "a" : "w");
	if (!pFile) return;

	fputs(static_cast<const char*>(m_p), pFile);

	fclose(pFile);
}

void CString::Map(CString& _sBuffer, std::function<char(char)> _fOperation) const {
	for (int uIndex = 0; uIndex < _sBuffer.Length(); uIndex++) {
		_sBuffer[uIndex] = _fOperation(_sBuffer[uIndex]);
	}
}