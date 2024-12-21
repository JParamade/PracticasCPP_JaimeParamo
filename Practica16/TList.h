#pragma once

#include "IComparable.h"

class TList {
public:
	class TListNode {
	public:
		TListNode(const IComparable& _rData);
		~TListNode();

		IComparable* m_pData;
		TListNode* m_pNext;
	};

	TList();
	TList(const TList& _rOther);
	~TList();

	int Size() const;
	int Push(const IComparable& _rData);
	IComparable* First();
	IComparable* Next();
	IComparable* Pop();
	void Reset();
	TList GetReverseList() const;

private:
	TListNode* m_pHead;
	TListNode* m_pTail;
	TListNode* m_pIterator;
	unsigned int m_uSize;
};