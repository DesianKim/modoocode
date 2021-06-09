#include "pch.h"
#include "TxtTable.h"
#include <algorithm>
Excel::TxtTable::TxtTable(int32_t row, int32_t col)
	: Table(row, col)
{
}

Excel::TxtTable::~TxtTable()
{
}

Excel::DataType Excel::TxtTable::print_table()
{
	DataType total_table;

	int32_t* col_max_wide = new int32_t[m_nMaxColSize];
	for (int32_t i = 0; i < m_nMaxColSize; ++i)
	{
		uint32_t max_wide = 2;
		for (int32_t j = 0; j < m_nMaxRowSize; ++j)
		{
			if (m_pDataTable[j][i] &&
				m_pDataTable[j][i]->stringify().length() > max_wide)
				max_wide = m_pDataTable[j][i]->stringify().length();
		}
		col_max_wide[i] = max_wide;
	}

	total_table += "   ";
	int32_t total_wide = 4;
	for (int32_t i = 0; i < m_nMaxColSize; ++i)
	{
		if (col_max_wide[i])
		{
			uint32_t max_len = std::max(2, col_max_wide[i]);
			total_table += " | " + col_num_to_str(i);
			total_table += repeat_char(max_len - col_num_to_str(i).length(), ' ');

			total_wide += (max_len + 3);
		}
	}

	total_table += "\n";
	for (int32_t i = 0; i < m_nMaxRowSize; ++i)
	{
		total_table += repeat_char(total_wide, '-');
		total_table += "\n" + std::to_string(i + 1);
		total_table += repeat_char(4 - std::to_string(i + 1).length(), ' ');

		for (int32_t j = 0; j < m_nMaxColSize; ++j)
		{
			if (col_max_wide[j])
			{
				int32_t max_len = std::max(2, col_max_wide[j]);

				DataType s = "";
				if (m_pDataTable[i][j])
					s = m_pDataTable[i][j]->stringify();
				total_table += " | " + s;
				total_table += repeat_char(max_len - s.length(), ' ');
			}
		}
		total_table += "\n";
	}
	return total_table;
}

Excel::DataType Excel::TxtTable::repeat_char(int32_t n, char c)
{
	DataType s = "";
	for (int32_t i = 0; i < n; ++i)
		s.push_back(c);

	return s;
}

Excel::DataType Excel::TxtTable::col_num_to_str(int32_t n)
{
	DataType s = "";
	if (n < 26)
		s.push_back('A' + n);
	else
	{
		char first = 'A' + n / 26 - 1;
		char second = 'A' + n % 26;

		s.push_back(first);
		s.push_back(second);
	}
	return s;
}