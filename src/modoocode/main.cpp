#include "pch.h"
#include <string>
#include <iostream>
#include "TMP.h"

int main()
{
	std::cout << "gcd (36, 24) :: " << GCD<36, 24>::value << std::endl;

	return 0;
}