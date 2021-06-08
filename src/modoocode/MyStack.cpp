#include "pch.h"
#include "MyStack.h"

Excel::Stack::Stack() noexcept
	: m_start(nullptr, "")
{
	m_pCurrent = &m_start;
}

Excel::Stack::~Stack() noexcept
{
	while (m_pCurrent != &m_start)
	{
		Node* temp = m_pCurrent->pPrev;
		m_pCurrent = temp->pPrev;

		delete temp;
	}
	delete m_pCurrent;
}

void Excel::Stack::push(const DataType& Data) noexcept
{
	Node* temp = new Node(m_pCurrent, Data);
	m_pCurrent = temp;
}

const Excel::DataType Excel::Stack::pop()
{
	if (m_pCurrent == &m_start)
		return m_start.nodeData;

	DataType tempData = m_pCurrent->nodeData;
	Node* pTemp = m_pCurrent;

	m_pCurrent = pTemp->pPrev;
	delete pTemp;

	return tempData;
}

const Excel::DataType& Excel::Stack::peek() const
{
	return m_pCurrent->nodeData;
}

bool Excel::Stack::isEmpty() const
{
	if (m_pCurrent == &m_start)
		return true;
	else
		return false;
}

Excel::Stack::Node::Node(Node* prev, DataType Data) noexcept
	: pPrev(prev),
	nodeData(Data)
{
}
