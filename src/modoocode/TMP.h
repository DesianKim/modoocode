#pragma once
#include <iostream>

//template <int32_t N>
//struct Int
//{
//	static const int32_t num = N;
//};
//
//template <typename T, typename U>
//struct add
//{
//	typedef Int<T::num + U::num> result;
//};

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

//bool is_prime(int32_t N)
//{
//	if (N == 2)
//		return true;
//	if (N == 3)
//		return true;
//
//	for (int32_t i = 2; i <= N / 2; ++i)
//	{
//		if (N % i == 0)
//			return false;
//	}
//	return true;
//}

template <int N>
struct INT 
{
	static const int num = N;
};

template <typename a, typename b>
struct add 
{
	using result = INT<a::num + b::num>;
};

template <typename a, typename b>
struct divide 
{
	using result = INT<a::num / b::num>;
};

using one = INT<1>;
using two = INT<2>;
using three = INT<3>;

template <typename N, typename d>
struct check_div 
{
	static const bool result = (N::num % d::num == 0) ||
		check_div<N, typename add<d, one>::result>::result;
};

template <typename N>
struct _is_prime 
{
	static const bool result = !check_div<N, two>::result;
};

template <>
struct _is_prime<two> 
{
	static const bool result = true;
};

template <>
struct _is_prime<three> 
{
	static const bool result = true;
};

template <typename N>
struct check_div<N, typename divide<N, two>::result> 
{
	static const bool result = (N::num % (N::num / 2) == 0);
};

template <int N>
struct is_prime 
{
	static const bool result = _is_prime<INT<N>>::result;
};