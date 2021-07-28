#include "pch.h"
#include <iostream>
#include <memory>

class A
{
public:
	A()
	{
		std::cout << "자원을 획득함!" << std::endl;
		data = new int[100];
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
	int32_t* data;
};

void do_somethig()
{
	std::unique_ptr<A> pa(new A());
	std::cout << "pa : ";
	pa->some();

	std::unique_ptr<A> pb = std::move(pa);
	std::cout << "pb : ";
	pb->some();
}

int main()
{	
	do_somethig();
	
	return 0;
}