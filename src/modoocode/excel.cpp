#include "pch.h"
#include "excel.h"

Excel::Vector::Vector(size_t n) noexcept
	: m_pData(new std::string[n]),
	m_nCapacity(n),
	m_nLength(0)
{
}

Excel::Vector::~Vector() noexcept
{
	if (m_pData)
	{
		delete[] m_pData;
		m_pData = nullptr;
	}
}

void Excel::Vector::push_back(const std::string& s)
{
	if (m_nCapacity <= m_nLength)
	{
		std::string* temp = new std::string[m_nCapacity * 2];
		
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
}

void Excel::Vector::remove(const size_t x)
{
	for (uint32_t i = x + 1; i < m_nLength; ++i)
	{
		m_pData[i - 1] = m_pData[i];
	}
	--m_nLength;
}

size_t Excel::Vector::size() const noexcept
{
	return m_nLength;
}

std::string& Excel::Vector::operator[](const size_t i) const
{
	return m_pData[i];
}
