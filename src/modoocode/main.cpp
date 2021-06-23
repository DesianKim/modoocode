#include "pch.h"
#include "TxtTable.h"
#include "NumberCell.h"
#include "ExprCell.h"
#include "StringCell.h"
#include <iostream>

int main()
{
	Excel::TxtTable table(5, 5);
	table.reg_cell(new Excel::NumberCell(2, 1, 1, &table), 1, 1);
	table.reg_cell(new Excel::NumberCell(3, 1, 2, &table), 1, 2);

	table.reg_cell(new Excel::NumberCell(4, 2, 1, &table), 2, 1);
	table.reg_cell(new Excel::NumberCell(5, 2, 2, &table), 2, 2);
	table.reg_cell(new Excel::ExprCell("B2+B3*(C2+C3-2)", 3, 3, &table), 3, 2);
	table.reg_cell(new Excel::StringCell("B2 + B3 * ( C2 + C3 - 2 ) = ", 3, 2, &table), 3, 1);
	
	std::cout << table;

	return 0;
}