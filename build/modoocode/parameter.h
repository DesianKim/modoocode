#pragma once
#include "interface.h"
#include <string>

namespace DataParma
{
	class param
	{
	public:
		param()
			: m_wsInputPath(L"")
			, m_wsOutputPath(L"")
			, m_nResolution(resolution::fullHD)
			, m_nFPS(fps::p60)
			, m_nRawformat(rawformat::yuyv)
		{
		}

		virtual ~param()
		{
		}

		param(const param& rhs)
		{
			(*this) = rhs;
		}

		param& operator=(const param& rhs)
		{
			m_wsInputPath = rhs.m_wsInputPath;
			m_wsOutputPath = rhs.m_wsOutputPath;
			m_nResolution = rhs.m_nResolution;
			m_nFPS = rhs.m_nFPS;
			m_nRawformat = rhs.m_nRawformat;

			return (*this);
		}

	public:
		void SetInputPath(const std::wstring& wsInputPath)
		{
			m_wsInputPath = wsInputPath;
		}

		void SetOutputPath(const std::wstring& wsOutputPath)
		{
			m_wsOutputPath = wsOutputPath;
		}

		void SetReolution(const resolution& nResolution)
		{
			m_nResolution = nResolution;
		}

		void SetFPS(const fps& nFPS)
		{
			m_nFPS = nFPS;
		}

		void SetRawformat(const rawformat& nRawformat)
		{
			m_nRawformat = nRawformat;
		}

		//get...

	protected:
		std::wstring m_wsInputPath;
		std::wstring m_wsOutputPath;
		resolution m_nResolution;
		fps m_nFPS;
		rawformat m_nRawformat;
	}; // class param
} // namespace function