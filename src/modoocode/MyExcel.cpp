#include "pch.h"
#include "MyExcel.h"
#include "TxtTable.h"
#include "CSVTable.h"
#include "HtmlTable.h"
#include "StringCell.h"
#include "NumberCell.h"
#include "DateCell.h"
#include "ExprCell.h"
#include <fstream>
#include <iostream>

Excel::MyExcel::MyExcel(int32_t nMaxRow, int32_t nMaxCol, int32_t nChoice = 0) noexcept
{
	switch (nChoice)
	{
	case 0:
		m_currentTable = new TxtTable(nMaxRow, nMaxCol);
		break;
	case 1:
		m_currentTable = new CSVTable(nMaxRow, nMaxCol);
		break;
	default:
		m_currentTable = new HtmlTable(nMaxRow, nMaxCol);
	}
}

Excel::MyExcel::~MyExcel() noexcept
{
}

bool Excel::MyExcel::parse_user_input(std::string s)
{
	int32_t next = 0;
	std::string command = "";
	for (int32_t i = 0; i < s.length(); ++i)
	{
		if (s[i] == ' ')
		{
			command = s.substr(0, i);
			next = i + 1;
			break;
		}
		else if (i == s.length() - 1)
		{
			command = s.substr(0, i + 1);
			next = i + 1;
			break;
		}
	}

	std::string to = "";
	for (int32_t i = next; i < s.length(); ++i)
	{
		if (s[i] == ' ' || i == s.length() - 1)
		{
			to = s.substr(next, i - next);
			next = i + 1;
			break;
		}
		else if (i == s.length() - 1)
		{
			to = s.substr(0, i + 1);
			next = i + 1;
			break;
		}
	}

	int32_t col = to[0] - 'A';
	int32_t row = atoi(to.c_str() + 1) - 1;

	std::string rest = s.substr(next);

	if (command == "sets")
	{
		m_currentTable->reg_cell(new StringCell(rest, row, col, m_currentTable), row, col);
	}
	else if (command == "setn")
	{
		m_currentTable->reg_cell(new NumberCell(atoi(rest.c_str()), row, col, m_currentTable), row, col);
	}
	else if (command == "setd")
	{
		m_currentTable->reg_cell(new DateCell(rest, row, col, m_currentTable), row, col);
	}
	else if (command == "sete")
	{
		m_currentTable->reg_cell(new ExprCell(rest, row, col, m_currentTable), row, col);
	}
	else if (command == "out")
	{
		std::ofstream out(to);
		out << *m_currentTable;
		std::cout << to << " 에 내용이 저장되었습니다" << std::endl;
	}
	else if (command == "exit")
	{
		return false;
	}

	return true;
}

void Excel::MyExcel::command_line()
{
	std::string s;
	std::getline(std::cin, s);

	while (parse_user_input(s))
	{
		std::cout << *m_currentTable << std::endl << ">> ";
		std::getline(std::cin, s);
	}
}
