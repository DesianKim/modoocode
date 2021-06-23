#pragma once
#include <string>
#include <cstdint>

namespace Excel
{
	using DataType = std::string;
	class Vector
	{
	public:
		Vector(size_t n = 1) noexcept;
		
		virtual ~Vector() noexcept;

	public:
		void push_back(const DataType& s);
		void remove(const size_t i);
		size_t size() const noexcept;
		DataType& operator[](const size_t x) const;

		Vector& operator=(const Vector& rhs) = delete;
		Vector(const Vector& rhs) = delete;

	private:
		DataType* m_pData;
		size_t m_nCapacity;
		size_t m_nLength;

	};//class Vector
}//namespace Excel