#pragma once
#include <iostream>
#include <string>

template <typename T>
void print(T arg)
{
	std::cout << arg << std::endl;
}

template <typename T, typename... Types>
void print(T arg, Types... args)
{
	std::cout << arg << ", ";
	print(args...);
}

size_t GetStringSize(const char* s)
{
	return strlen(s);
}

size_t GetStringSize(const std::string& s)
{
	return s.size();
}

template <typename T, typename... Types>
size_t GetStringSize(const T& s, Types... strs)
{
	return GetStringSize(s) + GetStringSize(strs...);
}

template <typename T, typename... Types>
std::string StrCat(const T& s, Types... strs)
{
	size_t total_size = GetStringSize(s, strs...);

	std::string concat_str;
	concat_str.reserve(total_size);

	concat_str = s;

	AppendToString(&concat_str, strs...);

	return concat_str;
}

void AppendToString(std::string* concat_str)
{
	return;
}

template <typename T, typename... Types>
void AppendToString(std::string* concat_str, const T& s, Types... strs)
{
	concat_str->append(s);
	AppendToString(concat_str, strs...);
}