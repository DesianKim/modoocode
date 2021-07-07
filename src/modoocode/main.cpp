#include "pch.h"
#include <string>
#include <iostream>
#include "TMP.h"
#include "Ratio.h"
#include "Unit.h"

int main()
{
	using one = Ratio<1, 1>;
	using zero = Ratio<0, 1>;

	quantity<double, Dim<one, zero, zero>> kg(1);
	quantity<double, Dim<zero, one, zero>> meter(1);
	quantity<double, Dim<zero, zero, one>> second(1);

	kg + kg;

	quantity<double, Dim<one, one, Ratio<-2, 1>>> F = kg * meter / (second * second);

	return 0;
}