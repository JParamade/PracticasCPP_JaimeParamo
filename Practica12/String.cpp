#include "String.h"

CString::CString(const char* str) {
	unsigned int uStringSize = static_cast<unsigned int>(strlen(str ? str : ""));
	m_p = new char[uStringSize + 1];
	strcpy_s(static_cast<char*>(m_p), uStringSize, str ? str : "");
}

CString::CString(const CString& str) {
	const char* sSource = static_cast<const char*>(str.m_p);
	unsigned int uStringSize = static_cast<unsigned int>(strlen(sSource));
	m_p = new char[uStringSize + 1];
	strcpy_s(static_cast<char*>(m_p), uStringSize, sSource);
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

	char* sTempString = new char[uStringSize + 1];

	strcpy_s(sTempString, strlen(sString1), sString1);
	strcat_s(sTempString, strlen(sString2), sString2);

	CString oResult(sTempString);

	delete[] sTempString;

	return oResult;
}

CString CString::operator+(char c) const {
	const char* sString = static_cast<const char*>(m_p);

	unsigned int uStringSize = static_cast<unsigned int>(strlen(sString));

	char* sTempString = new char[uStringSize + 2];

	strcpy_s(sTempString, strlen(sString), sString);

	sTempString[uStringSize - 1] = c;
	sTempString[uStringSize] = '\0';

	CString oResult(sTempString);

	delete[] sTempString;

	return oResult;
}

CString& CString::operator=(const CString& other) {
	if (this != &other) {
		delete[] static_cast<char*>(m_p);

		const char* sSource = static_cast<const char*>(other.m_p);
		unsigned int uStringSize = static_cast<unsigned int>(strlen(sSource));
		m_p = new char[uStringSize + 1];
		strcpy_s(static_cast<char*>(m_p), uStringSize, sSource);
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

}