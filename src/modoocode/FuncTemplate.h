#pragma once
#include <array>

struct Comp1
{
	bool operator()(int32_t a, int32_t b)
	{
		return a > b;
	}
};

struct Comp2
{
	bool operator()(int32_t a, int32_t b)
	{
		return a < b;
	}
};

template <typename T>
struct Compare
{
	bool operator()(const T&a, const T&b) const
	{
		return a < b;
	}
};

template <typename T>
T max(const T& a, const T& b)
{
	return a > b ? a : b;
}

template <typename Cont>
void bubble_sort(Cont& cont)
{
	for (int32_t i = 0; i < cont.size(); ++i)
		for (int32_t j = i + 1; j < cont.size(); ++j)
			if (cont[i] > cont[j])
				cont.swap(i, j);
}

template <typename Cont, typename Comp>
void bubble_sort(Cont& cont, Comp& comp)
{
	for (int32_t i = 0; i < cont.size(); ++i)
		for (int32_t j = i + 1; j < cont.size(); ++j)
			if (!comp(cont[i], cont[j]))
				cont.swap(i, j);
}

template <typename T, int num = 5>
T add_num(T t)
{
	return t + num;
}

template <typename T>
void print_array(const T& arr)
{
	for (int32_t i = 0; i < arr.size(); ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

template <typename T, typename Comp = Compare<T>>
T Min(T a, T b)
{
	Comp comp;
	if (comp(a, b))
		return a;
	return b;
}