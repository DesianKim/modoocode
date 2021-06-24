#include "pch.h"
#include "9_1_Vector.h"
#include <string>
#include <iostream>

int main()
{
	Template::Vector<int> int_vec;
	int_vec.push_back(3);
	int_vec.push_back(2);

	std::cout << "-------- int vector ----------" << std::endl;
	std::cout << "첫번째 원소 : " << int_vec[0] << std::endl;
	std::cout << "두번째 원소 : " << int_vec[1] << std::endl;

	Template::Vector<std::string> str_vec;
	str_vec.push_back("hello");
	str_vec.push_back("world");

	std::cout << "-------- std::string vector -------" << std::endl;
	std::cout << "첫번째 원소 : " << str_vec[0] << std::endl;
	std::cout << "두번째 원소 : " << str_vec[1] << std::endl;

	Template::Vector<bool> bool_vec;
	bool_vec.push_back(true);
	bool_vec.push_back(true);
	bool_vec.push_back(false);
	bool_vec.push_back(false);
	bool_vec.push_back(false);
	bool_vec.push_back(true);
	bool_vec.push_back(false);
	bool_vec.push_back(true);
	bool_vec.push_back(false);
	bool_vec.push_back(true);
	bool_vec.push_back(false);
	bool_vec.push_back(true);
	bool_vec.push_back(false);
	bool_vec.push_back(true);
	bool_vec.push_back(false);
	bool_vec.push_back(true);
	bool_vec.push_back(false);

	std::cout << "------- bool vector -------" << std::endl;
	for (int32_t i = 0; i < bool_vec.size(); ++i)
		std::cout << bool_vec[i];

	std::cout << std::endl;
	return 0;
}