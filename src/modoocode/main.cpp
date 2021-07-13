#include "pch.h"
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
#include <iostream>

template <class _RanIt>
void print(_RanIt begin, _RanIt end)
{
	for (_RanIt itr = begin; itr != end; ++itr)
		std::cout << "[" << *itr << "] ";
	std::cout << std::endl;
}

struct User
{
	User(std::string name, int32_t level)
		: m_sName(name),
		m_nLevel(level)
	{
	}

	bool operator==(const User& user) const
	{
		if (m_sName == user.m_sName && m_nLevel == user.m_nLevel)
			return true;
		return false;
	}

	std::string m_sName;
	int32_t m_nLevel;
};

class Party
{
public:
	bool add_user(std::string name, int32_t level)
	{
		User new_user(name, level);
		if (std::find(m_users.begin(), m_users.end(), new_user) != m_users.end())
			return false;
		m_users.emplace_back(new_user);
		return true;
	}

	bool can_join_dungeon()
	{
		return std::all_of(m_users.begin(), m_users.end(), [](User& user) {return user.m_nLevel >= 15; });
	}

	bool can_use_special_item()
	{
		return std::any_of(m_users.begin(), m_users.end(), [](User& user) {return user.m_nLevel >= 19; });
	}

private:
	std::vector<User> m_users;
};

int main()
{
	Party party;
	party.add_user("철수", 15);
	party.add_user("영희", 18);
	party.add_user("민수", 12);
	party.add_user("수빈", 19);
	party.add_user("수빈", 19);

	std::cout << std::boolalpha;
	std::cout << "던전 입장 가능 ? " << party.can_join_dungeon() << std::endl;
	std::cout << "특별 아이템 사용 가능 ? " << party.can_use_special_item() << std::endl;

	return 0;
}