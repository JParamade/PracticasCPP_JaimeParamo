#include "TList.h"

TList::TList() 
	: pIterator(nullptr)
	, pHead(nullptr)
	, uSize(0)
{}

TList::~TList() { Reset(); }

TList::TListNode::TListNode(const char* _sData)
	: sData(_sData)
	, pNext(nullptr) 
{}

TList::TListNode::~TListNode() { delete[] sData; }

int TList::Size() {	return uSize; }

int TList::Push(const char* _sString) {
	TListNode* pNewNode = new TListNode(_sString);

	if (!pHead) {
		pHead = pNewNode;
	}
	else {
		while (pIterator->pNext) pIterator = pIterator->pNext;

		pIterator->pNext = pNewNode;
	}

	uSize++;
	return uSize;
}

const char* TList::First() { 
	if (pHead) {
		pIterator = pHead;
		return pHead->sData;
	}
	else return "The list is empty.";
}

const char* TList::Next() {	
	if (pIterator->pNext) {
		pIterator = pIterator->pNext;

		return pIterator->sData;
	}
	else return "The list ended.";
}

const char* TList::Pop() {
	return "";
}

void TList::Reset() { 
	pIterator = pHead;
}