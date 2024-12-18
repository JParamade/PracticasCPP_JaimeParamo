#pragma once

#include <iostream>
#include "IStorable.h"

class CMyInt : public IStorable{
private:
	int m_iValue;

public:
	CMyInt(const int _iValue)
		: m_iValue(_iValue)
	{}

};

class CMyString : public IStorable {

};