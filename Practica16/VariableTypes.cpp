#include "VariableTypes.h"

CMyInt::CMyInt(const int _iValue)
	: m_iValue(_iValue)
{}

bool CMyInt::Equals(const IComparable& _rOther) const {
    const CMyInt* pOther = dynamic_cast<const CMyInt*>(&_rOther);
    
	if (pOther == nullptr) return false;
    
	return (m_iValue == pOther->m_iValue);
}

int CMyInt::GetValue() const {
	return m_iValue;
}

CMyString::CMyString(const char* _sValue) {
	unsigned int uStringSize = strlen(_sValue) + 1;
	m_sValue = new char[uStringSize];
	strcpy_s(m_sValue, uStringSize,_sValue);
}


CMyString::~CMyString() {
	delete[] m_sValue;
}

bool CMyString::Equals(const IComparable& _rOther) const {
	const CMyString* pOther = dynamic_cast<const CMyString*>(&_rOther);

	if (pOther == nullptr) return false;

	return (m_sValue == pOther->m_sValue);
}

const char* CMyString::GetValue() const {
	return m_sValue;
}