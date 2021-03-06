#include "pch.h"
#include <iostream>
#include <memory>
#include <vector>

class A
{
public:
	A()
	{
		std::cout << "자원을 획득함!" << std::endl;
		data = new int[100];
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
	std::vector<std::shared_ptr<A>> vec;

	vec.push_back(std::shared_ptr<A>(new A()));
	vec.push_back(std::shared_ptr<A>(vec[0]));
	vec.push_back(std::shared_ptr<A>(vec[1]));

	std::cout << "첫 번째 소멸!" << std::endl;
	vec.erase(vec.begin());

	std::cout << "다음 원소 소멸!" << std::endl;
	vec.erase(vec.begin());

	std::cout << "마지막 원소 소멸!" << std::endl;
	vec.erase(vec.begin());

	std::cout << "프로그램 종료!" << std::endl;

	return 0;
}