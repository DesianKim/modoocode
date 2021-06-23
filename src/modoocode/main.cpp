#include "pch.h"
#include "MyExcel.h"
#include <iostream>

int main()
{
	std::cout << "테이블 (타입) (최대 행 크기) (최대 열 크기) 를 순서대로 입력해주세요" << std::endl;
	std::cout << "* 참고 * " << std::endl;
	std::cout << "1 : 텍스트 테이블, 2: CSV 테이블, 3 : HTML 테이블" << std::endl;

	int32_t type, max_row, max_col;
	std::cin >> type >> max_row >> max_col;
	Excel::MyExcel m(max_row, max_col, type - 1);
	m.command_line();

	return 0;
}