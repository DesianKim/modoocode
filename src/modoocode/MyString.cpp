#include "pch.h"
#include "MyString.h"

MyString::MyString() 
{
	std::cout << "생성자 호출 ! " << std::endl;
	string_length = 0;
	memory_capacity = 0;
	string_content = NULL;
}

MyString::MyString(const char* str) 
{
	std::cout << "생성자 호출 ! " << std::endl;
	string_length = static_cast<int32_t>(strlen(str));
	memory_capacity = string_length;
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++) 
		string_content[i] = str[i];
}
MyString::MyString(const MyString &str) 
{
	std::cout << "복사 생성자 호출 ! " << std::endl;
	string_length = str.string_length;
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++)
		string_content[i] = str.string_content[i];
}
MyString::MyString(MyString &&str) 
{
	std::cout << "이동 생성자 호출 !" << std::endl;
	string_length = str.string_length;
	string_content = str.string_content;
	memory_capacity = str.memory_capacity;

	str.string_content = nullptr;
}
MyString::~MyString() {
	if (string_content) 
		delete[] string_content;
}

MyString &MyString::operator=(const MyString &s) 
{
	std::cout << "복사!" << std::endl;

	if (s.string_length > memory_capacity) 
	{
		delete[] string_content;
		string_content = new char[s.string_length];
		memory_capacity = s.string_length;
	}
	string_length = s.string_length;
	for (int i = 0; i != string_length; i++)
		string_content[i] = s.string_content[i];

	return *this;
}

MyString& MyString::operator=(MyString&& s)
{
	std::cout << "이동!" << std::endl;
	string_content = s.string_content;
	memory_capacity = s.memory_capacity;
	string_length = s.string_length;

	s.string_content = nullptr;
	s.memory_capacity = 0;
	s.string_length = 0;
	return *this;
}

int MyString::length() const 
{ 
	return string_length; 
}

void MyString::println() 
{
	for (int i = 0; i != string_length; i++) 
		std::cout << string_content[i];

	std::cout << std::endl;
}