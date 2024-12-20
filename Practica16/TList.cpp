#include "TList.h"
#include "IComparable.h"
#include <string>

TList::TList()
	: m_pIterator(nullptr)
	, m_pHead(nullptr)
	, m_pTail(nullptr)
	, m_uSize(0)
{}

TList::TList(const TList& _rOther)
	: m_pIterator(nullptr) 
	, m_pHead(nullptr)
	, m_pTail(nullptr)
	, m_uSize(0)
{
	TListNode* pTempNode = _rOther.m_pHead;

	while (pTempNode) {
		Push(pTempNode->m_sData);
		pTempNode = pTempNode->m_pNext;
	}
}

TList::~TList() { Reset(); }

TList::TListNode::TListNode(const char* _sData)
	: m_sData(nullptr)
	, m_pNext(nullptr)
{
	size_t uStringLength = strlen(_sData) + 1;
	m_sData = new char[uStringLength];
	strcpy_s(m_sData, uStringLength, _sData);
}

TList::TListNode::~TListNode() { delete[] m_sData; }

int TList::Size() const { return m_uSize; }

int TList::Push(const char* _sString) {
	TListNode* pNewNode = new TListNode(_sString);

	if (!m_pHead) m_pHead = m_pTail = pNewNode;
	else {
		m_pTail->m_pNext = pNewNode;
		m_pTail = pNewNode;
	}

	m_pIterator = m_pHead;
	m_uSize++;
	return m_uSize;
}

const char* TList::First() {
	if (m_pHead) {
		m_pIterator = m_pHead;

		return m_pHead->m_sData;
	}
	else return nullptr;
}

const char* TList::Next() {
	if (m_pIterator && m_pIterator->m_pNext) {
		m_pIterator = m_pIterator->m_pNext;

		return m_pIterator->m_sData;
	}
	else return nullptr;
}

const char* TList::Pop() {
	if (!m_pHead) return nullptr;

	TListNode* pTempNode = m_pHead;

	size_t uStringLength = strlen(pTempNode->m_sData) + 1;
	char* sTempString = new char[uStringLength];
	strcpy_s(sTempString, uStringLength, pTempNode->m_sData);

	m_pHead = m_pHead->m_pNext;

	delete pTempNode;

	m_uSize--;
	return sTempString;
}

void TList::Reset() {
	while (m_pHead) Pop();
	m_pTail = m_pIterator = nullptr;
}

TList TList::GetReverseList() const {
	TList lTempList;

	TListNode* pCurrentNode = m_pHead;

	while (pCurrentNode) {
		TListNode* pNewNode = new TListNode(pCurrentNode->m_sData);

		pNewNode->m_pNext = lTempList.m_pHead;
		lTempList.m_pHead = pNewNode;

		if (!lTempList.m_pTail) lTempList.m_pTail = pNewNode;

		lTempList.m_uSize++;
		pCurrentNode = pCurrentNode->m_pNext;
	}

	return lTempList;
}