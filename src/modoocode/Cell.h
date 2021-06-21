#pragma once
#include <cstdint>
#include <string>

namespace Excel
{
	// Forward declaration
	class Table;

	class Cell
	{
	public:
		Cell() = delete;
		Cell(int32_t nX, int32_t nY, Table* pTable) noexcept;
		virtual ~Cell() noexcept;

		virtual std::string stringify() = 0;
		virtual int32_t to_numeric() = 0;

	protected:
		int32_t m_nX, m_nY;
		Table* m_pTable;
	};// class Cell
}// namespace Excel