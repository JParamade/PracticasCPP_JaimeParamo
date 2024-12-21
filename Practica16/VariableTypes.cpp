#include "VariableTypes.h"

CMyInt::CMyInt(const int _iValue)
	: m_iValue(_iValue)
{}

CMyInt* CMyInt::Clone() const {
	return new CMyInt(*this);
}

bool CMyInt::Equals(const IComparable& _rOther) const {
    const CMyInt* pOther = dynamic_cast<const CMyInt*>(&_rOther);
    
	if (pOther == nullptr) return false;
    
	return m_iValue == pOther->m_iValue;
}

CMyString::CMyString(const char* _sValue) {
	unsigned int uStringSize = strlen(_sValue) + 1;
	m_sValue = new char[uStringSize];
	strcpy_s(m_sValue, uStringSize, _sValue);
}


CMyString::~CMyString() {
	delete[] m_sValue;
}

CMyString* CMyString::Clone() const {
	return new CMyString(*this);
}

bool CMyString::Equals(const IComparable& _rOther) const {
	const CMyString* pOther = dynamic_cast<const CMyString*>(&_rOther);

	if (pOther == nullptr) return false;

	return strcmp(m_sValue, pOther->m_sValue) == 0;
}