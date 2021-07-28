#include "pch.h"
#include <iostream>
#include <memory>
#include <vector>

class A
{
public:
	A(int i)
	{
		std::cout << "자원을 획득함!" << std::endl;
		data = new int[100];
		data[0] = i;
	}

	void some()
	{
		std::cout << "일반 포인터와 동일하게 사용가능!" << std::endl;
	}

	~A()
	{
		std::cout << "자원을 해제함!" << std::endl;
		delete[] data;
	}

private:
	int *data;
};

int main()
{	
	std::vector<std::unique_ptr<A>> vec;

	vec.emplace_back(std::make_unique<A>(1));
	vec.back()->some();

	return 0;
}