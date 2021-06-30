#pragma once
#include <cstdint>

template <int32_t N>
struct Int
{
	static const int32_t num = N;
};

template <typename T, typename U>
struct add
{
	typedef Int<T::num + U::num> result;
};