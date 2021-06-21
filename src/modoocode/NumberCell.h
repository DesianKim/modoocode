#pragma once
#include "Cell.h"
#include <string>

namespace Excel
{
	class NumberCell 
		: public Excel::Cell
	{
	public:
		NumberCell(int32_t data, int32_t x, int32_t y, Table* t);

		std::string stringify() override;
		int32_t to_numeric() override;

	private:
		int32_t m_data;
	};// class NumberCell : public Excel::Cell
}// namespace Excel