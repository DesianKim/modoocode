#pragma once

namespace Excel
{
	using NumStackDataType = double;

	class NumStack
	{
	public:
		NumStack();
		virtual ~NumStack();

		void push(const NumStackDataType& Data) noexcept;
		const NumStackDataType pop();
		const NumStackDataType& peek() const;
		bool isEmpty() const;

	private:
		struct Node
		{
			Node* pPrev;
			NumStackDataType nodeData;

			Node(Node* prev, NumStackDataType Data) noexcept;
		};// struct Node

		Node* m_pCurrent;
		Node m_start;
	};// class NumStack
}// namespace Excel

