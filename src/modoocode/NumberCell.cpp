#include "pch.h"
#include "NumberCell.h"

Excel::NumberCell::NumberCell(int32_t data, int32_t x, int32_t y, Table * t)
	: m_data(data),
	Cell(x, y, t)
{
}

std::string Excel::NumberCell::stringify()
{
	return std::to_string(m_data);
}

int32_t Excel::NumberCell::to_numeric()
{
	return m_data;
}
