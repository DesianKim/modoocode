#pragma once
#include "Ratio.h"

template <typename U, typename V, typename W>
struct Dim
{
	using M = U;	// kg
	using L = V;	// m
	using T = W;	// s

	using type = Dim<M, L, T>;
};

template <typename U, typename V>
struct add_dim_
{
	using type =
		Dim<typename Ratio_add<typename U::M, typename V::M>::type,
		typename Ratio_add<typename U::L, typename V::L>::type,
		typename Ratio_add<typename U::T, typename V::T>::type>;
};

template <typename U, typename V>
struct subtract_dim_
{
	using type =
		Dim<typename Ratio_subtract<typename U::M, typename V::M>::type,
		typename Ratio_subtract<typename U::L, typename V::L>::type,
		typename Ratio_subtract<typename U::T, typename V::T>::type>;
};

template <typename T, typename D>
struct quantity
{
	T q;
	using dim_type = D;

	quantity operator+(quantity<T, D> quant)
	{
		return quantity<T, D>(q + quant.q);
	}

	quantity operator-(quantity<T, D> quant)
	{
		return quantity<T, D>(q - quant.q);
	}

	quantity<T, D> operator*(T scalar) 
	{ 
		return quantity<T, D>(q * scalar); 
	}

	quantity<T, D> operator/(T scalar) 
	{ 
		return quantity<T, D>(q / scalar); 
	}

	template <typename D2>
	quantity <T, typename add_dim_<D, D2>::type> operator*(quantity<T, D2> quant)
	{
		return quantity<T, typename add_dim_<D, D2>::type>(q * quant.q);
	};

	template <typename D2>
	quantity<T, typename subtract_dim_<D, D2>::type> operator/(quantity<T, D2> quant)
	{
		return quantity<T, typename subtract_dim_<D, D2>::type>(q / quant.q);
	};

	quantity(T q)
		: q(q)
	{
	}
};