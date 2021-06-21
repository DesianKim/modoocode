#include "pch.h"
#include "StringCell.h"

Excel::StringCell::StringCell(std::string data, int32_t x, int32_t y, Table * t)
	: m_data(data),
	Cell(x, y, t)
{
}

std::string Excel::StringCell::stringify()
{
	return m_data;
}

int32_t Excel::StringCell::to_numeric()
{
	return 0;
}