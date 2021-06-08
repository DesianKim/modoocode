#include "pch.h"
#include "Table.h"

Excel::Table::Table(int32_t nMaxRowSize, int32_t nMaxColSize) noexcept
	: m_nMaxRowSize(nMaxRowSize),
	m_nMaxColSize(nMaxColSize)
{
	m_pDataTable = new Cell**[m_nMaxRowSize];
	for (int32_t i = 0; i < m_nMaxRowSize; ++i)
	{
		m_pDataTable[i] = new Cell*[m_nMaxColSize];
		for (int32_t j = 0; j < m_nMaxColSize; ++j)
		{
			m_pDataTable[i][j] = nullptr;
		}
	}
}

Excel::Table::~Table() noexcept
{
	for (int32_t i = 0; i < m_nMaxRowSize; ++i)
	{
		for (int32_t j = 0; j < m_nMaxColSize; ++j)
		{
			if (m_pDataTable[i][j])
				delete m_pDataTable[i][j];
		}
	}

	for (int32_t i = 0; i < m_nMaxRowSize; ++i)
	{
		delete[] m_pDataTable[i];
	}
	delete[] m_pDataTable;
}
