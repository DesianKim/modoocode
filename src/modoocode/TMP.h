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


template <uint32_t N>
struct fib
{
	static const uint32_t result = fib<N - 1>::result + fib<N - 2>::result;
};

template<>
struct fib<1>
{
	static const uint32_t result = 1;
};

template<>
struct fib<2>
{
	static const uint32_t result = 1;
};

bool is_prime(int32_t N)
{
	if (N == 2)
		return true;
	if (N == 3)
		return true;

	for (int32_t i = 2; i <= N / 2; ++i)
	{
		if (N % i == 0)
			return false;
	}
	return true;
}

template <>
struct is_prime<2>
{
	static const bool result = true;
};

template <>
struct is_prime<3>
{
	static const bool result = true;
};

template <int32_t N>
struct is_prime
{
	static const bool result = !check_div<N, 2>::result;
};

template <int32_t N, int32_t d>
struct check_div
{
	static const bool result = (N % d == 0) || check_div<N, d + 1>::result;
};

template <int32_t N>
struct check_div<N, N/2>
{
	static const bool result = (N % (N / 2) == 0);
};