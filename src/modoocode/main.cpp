#include "pch.h"
#include "TxtTable.h"
#include "CSVTable.h"
#include "HtmlTable.h"
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

	Excel::CSVTable table2(5, 5);
	std::ofstream out2("test.csv");

	table2.reg_cell(new Excel::Cell("Hello~", 0, 0, &table2), 0, 0);
	table2.reg_cell(new Excel::Cell("C++", 0, 1, &table2), 0, 1);

	table2.reg_cell(new Excel::Cell("Programming", 1, 1, &table2), 1, 1);
	out2 << table2;

	Excel::HtmlTable table3(5, 5);
	std::ofstream out3("test.html");

	table3.reg_cell(new Excel::Cell("Hello~", 0, 0, &table3), 0, 0);
	table3.reg_cell(new Excel::Cell("C++", 0, 1, &table3), 0, 1);

	table3.reg_cell(new Excel::Cell("Programming", 1, 1, &table3), 1, 1);
	out3 << table3;

	return 0;
}