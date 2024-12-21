#pragma once

class TList {
public:
	class TListNode {
	public:
		TListNode(const IComparable& _pData);
		~TListNode();

		IComparable* m_pData;
		TListNode* m_pNext;
	};

	TList();
	TList(const TList& _rOther);
	~TList();

	int Size() const;
	int Push(const char* _sString);
	const char* First();
	const char* Next();
	const char* Pop();
	void Reset();
	TList GetReverseList() const;

private:
	TListNode* m_pHead;
	TListNode* m_pTail;
	TListNode* m_pIterator;
	unsigned int m_uSize;
};