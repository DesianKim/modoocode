#include "pch.h"
#include <string>
#include <iostream>
#include "TMP.h"
#include "Ratio.h"

int main()
{
	std::cout << std::boolalpha;
	std::cout << "Is prime ? :: " << is_prime(2) << std::endl;
	std::cout << "Is prime ? :: " << is_prime(10) << std::endl;
	std::cout << "Is prime ? :: " << is_prime(11) << std::endl;
	std::cout << "Is prime ? :: " << is_prime(61) << std::endl;

	return 0;
}