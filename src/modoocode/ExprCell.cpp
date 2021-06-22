#include "pch.h"
#include "ExprCell.h"
#include "MyNumStack.h"
#include "Table.h"
#include "MyStack.h"

int32_t Excel::ExprCell::precedence(char c)
{
	switch (c)
	{
	case '(':
	case '[':
	case '{':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	}
	return 0;
}

void Excel::ExprCell::parse_expresstion()
{
	Stack stack;

	m_data.insert(0, "(");
	m_data.push_back(')');

	for (int32_t i = 0; i < m_data.length(); ++i)
	{
		if (isalpha(m_data[i]))
		{
			exp_vec.push_back(m_data.substr(i, 2));
			++i;
		}
		else if (isdigit(m_data[i]))
		{
			exp_vec.push_back(m_data.substr(i, 1));
		}
		else if (m_data[i] == '(' || m_data[i] == '[' || m_data[i] == '{')
		{
			stack.push(m_data.substr(i, 1));
		}
		else if (m_data[i] == ')' || m_data[i] == ']' || m_data[i] == '}')
		{
			std::string t = stack.pop();
			while (t != "(" && t != "[" && t != "{")
			{
				exp_vec.push_back(t);
				t = stack.pop();
			}
		}
		else if (m_data[i] == '+' || m_data[i] == '-' || m_data[i] == '*' || m_data[i] == '/')
		{
			while (!stack.isEmpty() && precedence(stack.peek()[0]) >= precedence(m_data[i]))
			{
				exp_vec.push_back(stack.pop());
			}
			stack.push(m_data.substr(i, 1));
		}
	}
}

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
