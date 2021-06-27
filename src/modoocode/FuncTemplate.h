#pragma once

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