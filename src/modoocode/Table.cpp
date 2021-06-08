#include "pch.h"
#include "Table.h"
#include "Cell.h"

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

void Excel::Table::reg_cell(Cell* c, int32_t row, int32_t col)
{
	if (!(row < m_nMaxRowSize && col < m_nMaxColSize))
		return;

	if (m_pDataTable[row][col])
		delete m_pDataTable[row][col];

	m_pDataTable[row][col] = c;
}

int Excel::Table::to_numeric(const DataType& sData)
{
	int32_t row = sData[0] - 'A';
	int32_t col = atoi(sData.c_str() + 1) - 1;

	if (row < m_nMaxRowSize && col < m_nMaxColSize)
	{
		if (m_pDataTable[row][col])
			return m_pDataTable[row][col]->to_numeric();
	}
	return 0;
}

int Excel::Table::to_numeric(int32_t row, int32_t col)
{
	if (row < m_nMaxRowSize && col < m_nMaxColSize && m_pDataTable[row][col])
		return m_pDataTable[row][col]->to_numeric();

	return 0;
}

Excel::DataType Excel::Table::stringify(const DataType& sData)
{
	int32_t row = sData[0] - 'A';
	int32_t col = atoi(sData.c_str() + 1) - 1;

	if (row < m_nMaxRowSize && col < m_nMaxColSize)
	{
		if (m_pDataTable[row][col])
			return m_pDataTable[row][col]->stringify();
	}
	return 0;
}

Excel::DataType Excel::Table::stringify(int32_t row, int32_t col)
{
	if (row < m_nMaxRowSize && col < m_nMaxColSize && m_pDataTable[row][col])
		return m_pDataTable[row][col]->stringify();

	return "";
}

std::ostream& operator<<(std::ostream& o, Excel::Table& table) {
	o << table.print_table();
	return o;
}