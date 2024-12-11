#pragma once

class TList {
public:
	class TListNode {
	public:
		TListNode(const char* _sData);
		~TListNode();

		char* sData;
		TListNode* pNext;
	};

	TList();
	~TList();

	int Size() const;
	int Push(const char* _sString);
	const char* First();
	const char* Next();
	const char* Pop();
	void Reset();

private:
	TListNode* pHead;
	TListNode* pTail;
	TListNode* pIterator;
	unsigned int uSize;
};