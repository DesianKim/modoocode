#pragma once

#include "parameter.h"

class Data : public DataParma::param
{
public:
	Data()
		: m_nConvertKey(0)
	{
	}

	Data(const Data& rhs)
	{
		(*this) = rhs;
	}

	Data& operator=(const Data& rhs)
	{
		m_nConvertKey = rhs.m_nConvertKey;
		return (*this);
	}

private:
	convertKey m_nConvertKey;
};