#pragma once

template <typename T>
class TList {
public:
	class TListNode {
	public:
		TListNode(const T& _rData)
			: m_pNext(nullptr)
		{
			m_pData = new T(_rData);
		}

		~TListNode() { delete m_pData; }

		T* m_pData;
		TListNode* m_pNext;
	};

	TList()
		: m_pIterator(nullptr)
		, m_pHead(nullptr)
		, m_pTail(nullptr)
		, m_uSize(0)
	{}

	TList(const TList& _rOther)
		: m_pIterator(nullptr)
		, m_pHead(nullptr)
		, m_pTail(nullptr)
		, m_uSize(0)
	{
		TListNode* pTempNode = _rOther.m_pHead;

		while (pTempNode) {
			Push(*(pTempNode->m_pData));
			pTempNode = pTempNode->m_pNext;
		}
	}

	~TList() { Reset(); }

	int Size() const { return m_uSize; }

	int Push(const T& _rData) {
		TListNode* pNewNode = new TListNode(_rData);

		if (!m_pHead) m_pHead = m_pTail = pNewNode;
		else {
			m_pTail->m_pNext = pNewNode;
			m_pTail = pNewNode;
		}

		m_pIterator = m_pHead;
		m_uSize++;
		return m_uSize;
	}

	T* First() {
		if (m_pHead) {
			m_pIterator = m_pHead;

			return m_pHead->m_pData;
		}
		else return nullptr;
	}

	T* Next() {
		if (m_pIterator && m_pIterator->m_pNext) {
			m_pIterator = m_pIterator->m_pNext;

			return m_pIterator->m_pData;
		}
		else return nullptr;
	}

	T* Pop() {
		if (!m_pHead) return nullptr;

		TListNode* pTempNode = m_pHead;

		T* pTempData = pTempNode->m_pData;

		m_pHead = m_pHead->m_pNext;

		delete pTempNode;

		m_uSize--;
		return pTempData;
	}

	void Reset() {
		while (m_pHead) Pop();
		m_pTail = m_pIterator = nullptr;
	}

	TList GetReverseList() const {
		TList lTempList;

		TListNode* pCurrentNode = m_pHead;

		while (pCurrentNode) {
			TListNode* pNewNode = new TListNode(*(pCurrentNode->m_pData));

			pNewNode->m_pNext = lTempList.m_pHead;
			lTempList.m_pHead = pNewNode;

			if (!lTempList.m_pTail) lTempList.m_pTail = pNewNode;

			lTempList.m_uSize++;
			pCurrentNode = pCurrentNode->m_pNext;
		}

		return lTempList;
	}

private:
	TListNode* m_pHead;
	TListNode* m_pTail;
	TListNode* m_pIterator;
	unsigned int m_uSize;
};