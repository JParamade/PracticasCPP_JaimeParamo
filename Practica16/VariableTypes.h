#pragma once

#include <iostream>
#include "IComparable.h"

class CMyInt : public IComparable {
private:
	int m_iValue;

public:
	CMyInt(const int _iValue);
	 
	virtual bool Equals(const IComparable& _other) const override;
};

class CMyString : public IComparable {
private:
	char* m_sValue;

public:
	CMyString(const char* _sValue);

	virtual bool Equals(const IComparable& _other) const override;
};