#include "pch.h"
#include "ExprCell.h"
#include "MyNumStack.h"
#include "Table.h"

int32_t Excel::ExprCell::to_numeric()
{
	double result = 0;
	NumStack stack;

	for (int32_t i = 0; i < exp_vec.size(); ++i)
	{
		std::string s = exp_vec[i];

		if (isalpha(s[0]))
		{
			stack.push(m_pTable->to_numeric(s));
		}
		else if (isdigit(s[0]))
		{
			stack.push(atoi(s.c_str()));
		}
		else
		{
			double y = stack.pop();
			double x = stack.pop();
			switch (s[0])
			{
			case '+':
				stack.push(x + y);
				break;
			case '-':
				stack.push(x - y);
				break;
			case '*':
				stack.push(x * y);
				break;
			case '/':
				stack.push(x / y);
				break;
			}
		}
	}
	return stack.pop();
}
