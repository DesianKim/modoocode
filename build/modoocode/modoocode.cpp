#include "pch.h"
#include "function.h"

int main()
{
	function func1;
	function func2(func1);

	func2 = func1;
}