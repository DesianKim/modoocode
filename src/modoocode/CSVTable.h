#pragma once
#include "Table.h"

namespace Excel
{
	using DataType = Excel::DataType;
	class CSVTable :
		public Excel::Table
	{
	public:
		CSVTable(int32_t row, int32_t col);

		DataType print_table() override;

	};// class CSVTable
}// namespace Excel
