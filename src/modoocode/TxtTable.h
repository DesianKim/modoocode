#pragma once
#include "Table.h"
#include <string>
namespace Excel
{
	using DataType = Excel::DataType;
	class TxtTable :
		public Excel::Table
	{
	public:
		TxtTable() = delete;
		TxtTable(int32_t row, int32_t col);
		virtual ~TxtTable();

		virtual DataType print_table() override;
	private:
		DataType repeat_char(int32_t n, char c);
		DataType col_num_to_str(int32_t n);

	};// class TxtTable
}// namespace Excel