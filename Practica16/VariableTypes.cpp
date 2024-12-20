#include "VariableTypes.h"

CMyInt::CMyInt(const int _iValue)
	: m_iValue(_iValue)
{}

bool CMyInt::Equals(const IComparable& _other) const {

}

CMyString::CMyString(const char* _sValue) {

}

bool CMyString::Equals(const IComparable& _other) const {

}