#include "pch.h"
#include <string>
#include <iostream>

std::string_view return_sv()
{
	std::string s = "this is a string";
	std::string_view sv = s;

	return sv;
}

int main()
{
	std::string_view sv = return_sv();

	std::cout << sv << std::endl;

	return 0;
}