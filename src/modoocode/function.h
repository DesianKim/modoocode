#pragma once
#include "Data.h"

class function
{
public:
	Data GetData() const
	{
		return m_Data;
	}

private:
	Data m_Data;
};