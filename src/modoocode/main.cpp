#include "pch.h"
#include <iostream>
#include <utility>
#include "MyString.h"

template <typename T>
void my_swap(T& a, T& b)
{
	T tmp(std::move(a));
	a = std::move(b);
	b = std::move(tmp);
}

int main()
{
	MyString str1("abc");
	MyString str2("def");
	std::cout << "Swap 전 -----" << std::endl;
	str1.println();
	str2.println();

	std::cout << "Swap 후 -----" << std::endl;
	my_swap(str1, str2);
	str1.println();
	str2.println();
	
	return 0;
}