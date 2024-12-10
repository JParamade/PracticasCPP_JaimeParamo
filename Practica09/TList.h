#pragma once

class TList {
public:
	TList();
	~TList();

	int Size();
	int Push(const char* _sString);
	const char* First();
	const char* Next();
	const char* Pop();
	void Reset();

private:
	struct TListNode {
		TListNode(const char* _sData);
		~TListNode();

		const char* sData;
		TListNode* pNext;
	};

	TListNode* pHead;
	TListNode* pIterator;
	unsigned int uSize;
};