#include "pch.h"
#include <string>
#include <iostream>
#include "TMP.h"
#include "Ratio.h"
#include "Unit.h"

template <typename T, typename D>
std::ostream& operator<<(std::ostream& out, const quantity<T, D>& q)
{
	out << q.q << "kg^" << D::M::num / D::M::den << "m^" << D::L::num / D::L::den
		<< "s^" << D::T::num / D::T::den;

	return out;
}

int main()
{
	using one = Ratio<1, 1>;
	using zero = Ratio<0, 1>;

	quantity<double, Dim<one, zero, zero>> kg(1);
	quantity<double, Dim<zero, one, zero>> meter(1);
	quantity<double, Dim<zero, zero, one>> second(1);

	auto F = kg * meter / (second * second);
	std::cout << "2 kg 물체를 3m/s^2 의 가속도로 밀기 위한 힘의 크기는 ?" << F << std::endl;

	return 0;
}