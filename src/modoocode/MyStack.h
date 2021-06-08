#pragma once
#include <string>

namespace Excel
{
	using DataType = std::string;
	class Stack
	{
	public:
		Stack() noexcept;
		virtual ~Stack() noexcept;

		void push(const DataType& Data) noexcept;
		const DataType pop();
		const DataType& peek() const;
		bool isEmpty() const;

	private:
		struct Node
		{
			Node* pPrev;
			DataType nodeData;

			Node(Node* prev, DataType Data) noexcept;
		}; // struct Node

		Node* m_pCurrent;
		Node m_start;
	};// class Stack
}// namespace Excel

