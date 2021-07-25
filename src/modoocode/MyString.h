#pragma once
#include <iostream>
#include <cstring>

class MyString {
public:
	MyString();
	~MyString();

	MyString(const char *str);
	MyString(const MyString &str);
	MyString(MyString &&str);

	MyString &operator=(const MyString &s);
	MyString& operator=(MyString&& s);

	int length() const;
	void println();

private:
	char* string_content;
	int string_length;

	int memory_capacity;
};