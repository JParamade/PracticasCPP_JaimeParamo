#pragma once

template <typename T>
class TList {
public:
	class TListNode {
	public:
		TListNode(T _rData)
			: m_Data(_rData)
			, m_pNext(nullptr)
		{}
		~TListNode() { delete[] m_Data; }

		T m_Data;
		TListNode* m_pNext;
	};

	TList()
		: pIterator(nullptr)
		, pHead(nullptr)
		, pTail(nullptr)
		, uSize(0)
	{}
	~TList() { Reset(); }

	int Size() const { return uSize; }

	int Push(T _oElement) {
		TListNode* pNewNode = new TListNode(_oElement);

		if (!pHead) pHead = pTail = pNewNode;
		else {
			pTail->m_pNext = pNewNode;
			pTail = pNewNode;
		}

		pIterator = pHead;
		uSize++;
		return uSize;
	}

	T First() {
		if (pHead) {
			pIterator = pHead;

			return pHead->m_Data;
		}
		else return nullptr;
	}

	T Next() {
		if (pIterator && pIterator->m_pNext) {
			pIterator = pIterator->m_pNext;

			return pIterator->m_Data;
		}
		else return nullptr;
	}

	T Pop() {
		if (!pHead) return nullptr;

		TListNode* pTempNode = pHead;

		T oTempData = pHead->m_Data;

		pHead = pHead->m_pNext;

		delete pTempNode;

		uSize--;
		return oTempData;
	}

	void Reset() {
		while (pHead) Pop();
		pTail = pIterator = nullptr;
	}

private:
	TListNode* pHead;
	TListNode* pTail;
	TListNode* pIterator;
	unsigned int uSize;
};