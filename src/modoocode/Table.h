#pragma once
#include <cstdint>
#include <string>

namespace Excel
{
	// Forward declaration
	class Cell;

	using DataType = std::string;
	class Table
	{
	public:
		Table() = delete;
		Table(int32_t nMaxRowSize, int32_t nMaxColSize) noexcept;
		virtual ~Table() noexcept;

		void reg_cell(Cell* c, int32_t row, int32_t col);
		int to_numeric(const DataType& sData);
		int to_numeric(int32_t row, int32_t col);
		DataType stringify(const DataType& sData);
		DataType stringify(int32_t row, int32_t col);

		virtual DataType print_table() = 0;

	protected:
		int32_t m_nMaxRowSize, m_nMaxColSize;
		Cell*** m_pDataTable;
	};// class Table
}// namespace Excel