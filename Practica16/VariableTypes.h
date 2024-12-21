#pragma once

#include <iostream>
#include "IComparable.h"

class CMyInt : public IComparable {
private:
	int m_iValue;

public:
	CMyInt(const int _iValue);
	 
	virtual CMyInt* Clone() const override;
	virtual bool Equals(const IComparable& _other) const override;
};

class CMyString : public IComparable {
private:
	char* m_sValue;

public:
	CMyString(const char* _sValue);
	~CMyString();

	virtual CMyString* Clone() const override;
	virtual bool Equals(const IComparable& _other) const override;
};