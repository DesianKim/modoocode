#include "pch.h"
#include "HtmlTable.h"

Excel::HtmlTable::HtmlTable(int32_t row, int32_t col) noexcept
	: Table(row, col)
{
}

Excel::DataType Excel::HtmlTable::print_table()
{
	DataType s = "<table border='1' cellpadding='10'>";
	for (int32_t i = 0; i < m_nMaxRowSize; ++i)
	{
		s += "<tr>";
		for (int32_t j = 0; j < m_nMaxColSize; ++j)
		{
			s += "<td>";
			if (m_pDataTable[i][j])
				s += m_pDataTable[i][j]->stringify();
			s += "</td>";
		}
		s += "</tr>";
	}
	s += "</table>";
	return s;
}
