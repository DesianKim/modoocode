#pragma once
#include "Cell.h"
#include <string>

namespace Excel
{
	class StringCell 
		: public Excel::Cell
	{
	public:
		StringCell(std::string data, int32_t x, int32_t y, Table* t);

		std::string stringify() override;
		int32_t to_numeric() override;

	private:
		std::string m_data;
	};// class StringCell : public Excel::Cell
}// namespace Excel