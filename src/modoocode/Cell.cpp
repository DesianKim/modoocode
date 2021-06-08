#include "pch.h"
#include "Cell.h"

Excel::Cell::Cell(std::string sData, int32_t nX, int32_t nY, Table* pTable)
	: m_sData(sData),
	m_nX(nX),
	m_nY(nY),
	m_pTable(pTable)
{
}

Excel::Cell::~Cell()
{
}

std::string Excel::Cell::stringify()
{
	return m_sData;
}

int32_t Excel::Cell::to_numeric()
{
	return 0;
}
