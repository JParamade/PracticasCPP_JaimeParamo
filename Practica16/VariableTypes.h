#pragma once

#include <iostream>
#include "IComparable.h"

class CMyInt : public IComparable {
private:
	int m_iValue;

public:
	CMyInt(const int _iValue)
		: m_iValue(_iValue)
	{}

};

class CMyString : public IComparable {
private:
	char* m_sValue;

public:
	CMyString(char* _sValue)
		: m_sValue(_sValue)
	{}
};