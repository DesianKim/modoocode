#include "pch.h"
#include "CSVTable.h"

Excel::CSVTable::CSVTable(int32_t row, int32_t col)
	: Table(row, col)
{
}

Excel::DataType Excel::CSVTable::print_table()
{
	DataType s = "";
	for (int32_t i = 0; i < m_nMaxRowSize; ++i)
	{
		for (int32_t j = 0; j < m_nMaxRowSize; ++j)
		{
			if (j >= 1)
				s += ",";

			DataType temp;
			if (m_pDataTable[i][j])
				temp = m_pDataTable[i][j]->stringify();

			for (int32_t k = 0; k < temp.length(); ++k)
			{
				if (temp[k] == '"')
				{
					temp.insert(k, 1, '"');
					++k;
				}
			}
			temp = '"' + temp + '"';
			s += temp;
		}
		s += '\n';
	}
	return s;
}
