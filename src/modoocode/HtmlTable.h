#pragma once
#include "Table.h"

namespace Excel
{
	using DataType = Excel::DataType;
	class HtmlTable :
		public Excel::Table
	{
	public:
		HtmlTable(int32_t row, int32_t col) noexcept;

		DataType print_table() override;
	};// class HtmlTable
}// namespace Excel