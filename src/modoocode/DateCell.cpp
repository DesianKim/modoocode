#include "pch.h"
#include "DateCell.h"
#include <time.h>

Excel::DateCell::DateCell(std::string s, int32_t x, int32_t y, Table * t)
	: Cell(x, y, t)
{
	int32_t year = atoi(s.c_str());
	int32_t month = atoi(s.c_str() + 5);
	int32_t day = atoi(s.c_str() + 8);

	tm timeinfo;

	timeinfo.tm_year = year - 1900;
	timeinfo.tm_mon = month - 1;
	timeinfo.tm_mday = day;
	timeinfo.tm_hour = 0;
	timeinfo.tm_min = 0;
	timeinfo.tm_sec = 0;

	m_data = mktime(&timeinfo);
}

std::string Excel::DateCell::stringify()
{
	char buf[50];
	tm temp;

	localtime_s(&temp, &m_data);

	strftime(buf, 50, "%F", &temp);

	return std::string(buf);
}

int32_t Excel::DateCell::to_numeric()
{
	return static_cast<int32_t>(m_data);
}
