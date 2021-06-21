#pragma once
#include "Cell.h"
#include <string>

namespace Excel
{
	class DateCell
		: public Excel::Cell
	{
	public:
		DateCell(std::string s, int32_t x, int32_t y, Table* t);

		std::string stringify() override;
		int32_t to_numeric() override;

	private:
		time_t m_data;
	};// class DateCell : public Excel::Cell
}// namespace Excel