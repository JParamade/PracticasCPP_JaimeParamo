#include "String.h"

CString::CString(const char* str = "") {
	unsigned int uStringSize = strlen(str ? str : "");
	m_p = new char(uStringSize);
	strcpy_s(static_cast<char*>(m_p), uStringSize, str ? str : "");
}

CString::CString(const CString& str) {
	const char* sSource = static_cast<const char*>(str.m_p);
	unsigned int uStringSize = strlen(sSource);
	m_p = new char(uStringSize);
	strcpy_s(static_cast<char*>(m_p), uStringSize, sSource);
}

CString::~CString() {
	delete[] static_cast<char*>(m_p);
}