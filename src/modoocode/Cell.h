#pragma once
#include <cstdint>
#include <string>

// Forward declaration
class Table;

namespace Excel
{
	class Cell
	{
	public:
		Cell() = delete;
		Cell(std::string sData, int32_t nX, int32_t nY, Table* pTable);
		virtual ~Cell();

		virtual std::string stringify();
		virtual int32_t to_numeric();

	protected:
		int32_t m_nX, m_nY;
		Table* m_pTable;
		std::string m_sData;
	};// class Cell
}// namespace Excel