#pragma once
#include <cstdint>

namespace Template
{
	template <typename T>
	class Vector
	{
	public:
		using value_type = T;

		Vector(size_t n = 1) noexcept
			: m_pData(new T[n]),
			m_nCapacity(n),
			m_nLength(0)
		{
		}

		virtual ~Vector() noexcept
		{
			if (m_pData)
			{
				delete[] m_pData;
				m_pData = nullptr;
			}
		}

	public:
		void push_back(const T& s)
		{
			if (m_nCapacity <= m_nLength)
			{
				T* temp = new T[m_nCapacity * 2];

				for (uint32_t i = 0; i < m_nLength; ++i)
				{
					temp[i] = m_pData[i];
				}

				delete[] m_pData;
				m_pData = temp;

				m_nCapacity *= 2;
			}

			m_pData[m_nLength] = s;
			++m_nLength;
		};

		void remove(const size_t x)
		{
			for (size_t i = x + 1; i < m_nLength; ++i)
			{
				m_pData[i - 1] = m_pData[i];
			}
			--m_nLength;
		};

		size_t size() const noexcept
		{
			return m_nLength;
		};

		void swap(int32_t i, int32_t j)
		{
			T temp = m_pData[i];
			m_pData[i] = m_pData[j];
			m_pData[j] = temp;
		}

		T& operator[](const size_t i) const
		{
			return m_pData[i];
		};

		Vector& operator=(const Vector& rhs) = delete;
		Vector(const Vector& rhs) = delete;

	private:
		T* m_pData;
		size_t m_nCapacity;
		size_t m_nLength;

	};// class Vector<T>

	template<>
	class Vector<bool>
	{
	public:
		using value_type = bool;

		Vector(int32_t n = 1)
			:m_pData(new uint32_t[n / 32 + 1]),
			m_nCapacity(n / 32 + 1),
			m_nLength(0)
		{
			for (size_t i = 0; i < m_nCapacity; ++i)
				m_pData[i] = 0;
		}

		virtual ~Vector()
		{
			if (m_pData)
				delete[] m_pData;
		}

	public:
		void push_back(bool s)
		{
			if (m_nCapacity * 32 <= m_nLength)
			{
				uint32_t* temp = new uint32_t[m_nCapacity * 2];
				for (size_t i = 0; i < m_nCapacity; ++i)
					temp[i] = m_pData[i];
				for (size_t i = m_nCapacity; i < 2 * m_nCapacity; ++i)
					temp[i] = 0;

				delete[] m_pData;
				m_pData = temp;
				m_nCapacity *= 2;
			}

			if (s)
				m_pData[m_nLength / 32] |= (1 << (m_nLength % 32));

			++m_nLength;
		}

		bool operator[](int32_t i)
		{
			return (m_pData[i / 32] & (1 << (i % 32))) != 0;
		}

		void remove(int32_t x)
		{
			for (size_t i = x + 1; i < m_nLength; ++i)
			{
				size_t prev = i - 1;
				size_t curr = i;

				if (m_pData[curr / 32] & (1 << (curr % 32)))
					m_pData[prev / 32] |= (1 << (prev % 32));
				else
				{
					uint32_t all_ones_except_prev = 0xFFFFFFFF;
					all_ones_except_prev ^= (1 << (prev % 32));
					m_pData[prev / 32] &= all_ones_except_prev;
				}
			}
			--m_nLength;
		}

		size_t size()
		{
			return m_nLength;
		}

	private:
		uint32_t* m_pData;
		size_t m_nCapacity;
		size_t m_nLength;
	};// class Vector<bool>
}// namespace Template
