#pragma once
#include <iostream>

namespace Template
{
	template <typename T, uint32_t N>
	class Array
	{
	public:
		Array(T(&arr)[N])
		{
			for (int32_t i = 0; i < N; ++i)
				m_data[i] = arr[i];
		}
		virtual ~Array()
		{
		}

	public:
		T* get_array()
		{
			return m_data;
		}

		uint32_t size()
		{
			return N;
		}

		void print_all()
		{
			for (int32_t i = 0; i < N; ++i)
				std::cout << m_data[i] << ", ";
			std::cout << std::endl;
		}

	private:
		T m_data[N];
	};// class Array
}// namespace Template