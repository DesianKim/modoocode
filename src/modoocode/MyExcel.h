#pragma once
#include <string>

namespace Excel
{
	class Table;
}

namespace Excel
{
	class MyExcel
	{
	public:
		MyExcel() = delete;
		MyExcel(int32_t nMaxRow, int32_t nMaxCol, int32_t nChoice) noexcept;
		virtual ~MyExcel() noexcept;

	public:
		bool parse_user_input(std::string s);
		void command_line();

	private:
		Table* m_currentTable;
	};// class Excel
}// namespace Excel
