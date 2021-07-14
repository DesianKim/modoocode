#include "pch.h"
#include "MyString.h"
#include <string>
#include <iostream>

int main()
{
	std::basic_string<char, my_char_traits> my_s1 = "1a";
	std::basic_string<char, my_char_traits> my_s2 = "a1";

	std::cout << "숫자의 우선순위가 더 낮은 문자열 : " << std::boolalpha << (my_s1 < my_s2) << std::endl;
	
	std::string s1 = "1a";
	std::string s2 = "a1";
	
	std::cout << "일반 문자열 : " << std::boolalpha << (s1 < s2) << std::endl;

	return 0;
}