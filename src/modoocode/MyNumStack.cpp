#include "pch.h"
#include "MyNumStack.h"

Excel::NumStack::NumStack() noexcept
	: m_start(nullptr, 0)
{
	m_pCurrent = &m_start;
}


Excel::NumStack::~NumStack() noexcept
{
	while (m_pCurrent != &m_start)
	{
		Node* temp = m_pCurrent;
		m_pCurrent = m_pCurrent->pPrev;

		delete temp;
	}
}

void Excel::NumStack::push(const NumStackDataType& Data) noexcept
{
	Node* temp = new Node(m_pCurrent, Data);
	m_pCurrent = temp;
}

const Excel::NumStackDataType Excel::NumStack::pop()
{
	if (m_pCurrent == &m_start)
		return m_start.nodeData;

	NumStackDataType tempData = m_pCurrent->nodeData;
	Node* pTemp = m_pCurrent;

	m_pCurrent = pTemp->pPrev;
	delete pTemp;

	return tempData;
}

const Excel::NumStackDataType& Excel::NumStack::peek() const
{
	return m_pCurrent->nodeData;
}

bool Excel::NumStack::isEmpty() const
{
	if (m_pCurrent == &m_start)
		return true;
	else
		return false;
}

Excel::NumStack::Node::Node(Node* prev, NumStackDataType Data) noexcept
	: pPrev(prev),
	nodeData(Data)
{
}
