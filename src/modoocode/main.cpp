#include "pch.h"
#include <iostream>
#include <string>
#include <unordered_set>

template <class _Ty>
void print_undordered_set(const std::unordered_set<_Ty>& s)
{
	for (const auto& elem : s)
		std::cout << elem << std::endl;
}

template <class _Ty>
void is_exist(const std::unordered_set<_Ty>& s, _Ty key)
{
	auto itr = s.find(key);
	if (itr != s.end())
		std::cout << key << " 가 존재!" << std::endl;
	else
		std::cout << key << " 가 없다" << std::endl;
}

class Todo
{
public:
	Todo(int32_t nPriority, std::string sJob_desc)
		: m_nPriority(nPriority),
		m_sJob_desc(sJob_desc)
	{
	}

	virtual ~Todo()
	{
	}

public:
	bool operator==(const Todo& t) const
	{
		if (m_nPriority == t.m_nPriority && m_sJob_desc == t.m_sJob_desc)
			return true;
		return false;
	}

	friend std::ostream& operator<<(std::ostream& o, const Todo& t);
	friend struct std::hash<Todo>;

private:
	int32_t m_nPriority;
	std::string m_sJob_desc;
};

namespace std
{
	template <>
	struct hash<Todo>
	{
		size_t operator()(const Todo& t) const
		{
			hash<std::string> hash_func;

			return t.m_nPriority ^ (hash_func(t.m_sJob_desc));
		}
	};
}// namespace std

std::ostream& operator<<(std::ostream& o, const Todo& t)
{
	o << "[중요도 : " << t.m_nPriority << " ] " << t.m_sJob_desc;
	return o;
}

int main()
{
	std::unordered_set<Todo> todos;

	todos.insert(Todo(1, "농구 하기"));
	todos.insert(Todo(2, "수학 숙제 하기"));
	todos.insert(Todo(1, "프로그래밍 프로젝트"));
	todos.insert(Todo(3, "친구 만나기"));
	todos.insert(Todo(2, "영화 보기"));

	print_undordered_set(todos);
	std::cout << "---------------" << std::endl;

	return 0;
}