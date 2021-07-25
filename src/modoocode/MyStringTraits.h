#pragma once
#include <cctype>
#include <iostream>
#include <string>

struct my_char_traits : public std::char_traits<char>
{
	static int32_t get_real_rank(char c)
	{
		if (isdigit(c))
			return c + 256;
		return c;
	}

	static bool lt(char c1, char c2)
	{
		return get_real_rank(c1) < get_real_rank(c2);
	}

	static int32_t compare(const char* s1, const char* s2, size_t n)
	{
		while (n-- != 0)
		{
			if (get_real_rank(*s1) < get_real_rank(*s2))
				return -1;
			if (get_real_rank(*s1) > get_real_rank(*s2))
				return 1;
			++s1;
			++s2;
		}
		return 0;
	}
};