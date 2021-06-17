#include "pch.h"
#include "TxtTable.h"
#include <fstream>
#include <iostream>

int main()
{
	Excel::TxtTable table(5, 5);
	std::ofstream out("test.txt");

	table.reg_cell(new Excel::Cell("Hello~", 0, 0, &table), 0, 0);
	table.reg_cell(new Excel::Cell("C++", 0, 1, &table), 0, 1);

	table.reg_cell(new Excel::Cell("Programming", 1, 1, &table), 1, 1);
	std::cout << std::endl << table;
	out << table;
	return 0;
}