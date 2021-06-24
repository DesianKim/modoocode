#pragma once

namespace Template
{
	template <typename T>
	class Vector
	{
	public:
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

	};//class Vector
}// namespace Template