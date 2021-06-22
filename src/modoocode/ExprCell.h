#pragma once
#include "Cell.h"
#include <string>
#include "MyVector.h"

namespace Excel
{
	class ExprCell
		: public Excel::Cell
	{
	private:
		int32_t precedence(char c);
		void parse_expresstion();

	public:
		ExprCell(std::string data, int32_t x, int32_t y, Table* t);

		std::string stringify() override;
		int32_t to_numeric() override;

	private:
		std::string m_data;
		std::string* parsed_expr;
		Excel::Vector exp_vec;
	};// class ExprCell : public Excel::Cell
}// namespace Excel