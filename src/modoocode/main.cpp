#include "pch.h"
#include <string>
#include <iostream>
#include "VariadicTemplate.h"

int main()
{
	print(1, 3.1, "abs");
	print(1, 2, 3, 4, 5, 6, 7);

	return 0;
}