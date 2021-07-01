#pragma once
#include <iostream>

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

template <int32_t N>
struct Factorial
{
	static const int32_t result = N * Factorial<N - 1>::result;
};

template <>
struct Factorial<1>
{
	static const int32_t result = 1;
};

template <int32_t X, int32_t Y>
struct GCD
{
	static const int32_t value = GCD<Y, X % Y>::value;
};

template <int32_t X>
struct GCD<X, 0>
{
	static const int32_t value = X;
};