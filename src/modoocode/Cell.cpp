#include "pch.h"
#include "Cell.h"
#include "Table.h"

Excel::Cell::Cell( int32_t nX, int32_t nY, Table* pTable) noexcept
	:m_nX(nX),
	m_nY(nY),
	m_pTable(pTable)
{
}

Excel::Cell::~Cell() noexcept
{
}