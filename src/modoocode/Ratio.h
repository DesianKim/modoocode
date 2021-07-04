#pragma once
#include <cstdint>

template <int32_t N, int32_t D = 1>
struct Ratio
{
	using type = Ratio<N, D>;
	static const int32_t num = N;
	static const int32_t den = D;
};

template <class R1, class R2>
struct _Ratio_add
{
	using type = Ratio<R1::num * R2::den + R2::num * R1::den, R1::den * R2::den>;
};

template <class R1, class R2>
struct Ratio_add : _Ratio_add<R1, R2>::type
{
};

template <class R1, class R2>
struct _Ratio_subtract
{
	using type = Ratio<R1::num * R2::den - R2::num * R1::den, R1::den * R2::den>;
};

template <class R1, class R2>
struct Ratio_subtract : _Ratio_subtract<R1, R2>::type
{
};

template <class R1, class R2>
struct _Ratio_multiply
{
	using type = Ratio<R1::num * R2::num, R1::den * R2::den>;
};

template <class R1, class R2>
struct Ratio_multiply : _Ratio_multiply<R1, R2>::type
{
};

template <class R1, class R2>
struct _Ratio_divide
{
	using type = Ratio<R1::num * R2::den, R1::den * R2::num>;
};

template <class R1, class R2>
struct Ratio_divide : _Ratio_divide<R1, R2>::type
{
};