#include "pch.h"
#include <string>
#include <iostream>
#include "VariadicTemplate.h"

int main()
{
	std::cout << StrCat(std::string("this"), " ", "is", " ", std::string("a"),
		" ", std::string("sentence"));

	return 0;
}