#include "TList.h"
#include <string>

TList::TList()
	: pIterator(nullptr)
	, pHead(nullptr)
	, pTail(nullptr)
	, uSize(0)
{}

TList::TList(const TList& _rOther)
	: pIterator(nullptr) 
	, pHead(nullptr)
	, pTail(nullptr)
	, uSize(0)
{
	TListNode* pTempNode = _rOther.pHead;

	while (pTempNode) {
		Push(pTempNode->sData);
		pTempNode = pTempNode->pNext;
	}
}

TList::~TList() { Reset(); }

TList::TListNode::TListNode(const char* _sData)
	: sData(nullptr)
	, pNext(nullptr)
{
	size_t uStringLength = strlen(_sData) + 1;
	sData = new char[uStringLength];
	strcpy_s(sData, uStringLength, _sData);
}

TList::TListNode::~TListNode() { delete[] sData; }

int TList::Size() const { return uSize; }

int TList::Push(const char* _sString) {
	TListNode* pNewNode = new TListNode(_sString);

	if (!pHead) pHead = pTail = pNewNode;
	else {
		pTail->pNext = pNewNode;
		pTail = pNewNode;
	}

	pIterator = pHead;
	uSize++;
	return uSize;
}

const char* TList::First() {
	if (pHead) {
		pIterator = pHead;

		return pHead->sData;
	}
	else return nullptr;
}

const char* TList::Next() {
	if (pIterator && pIterator->pNext) {
		pIterator = pIterator->pNext;

		return pIterator->sData;
	}
	else return nullptr;
}

const char* TList::Pop() {
	if (!pHead) return nullptr;

	TListNode* pTempNode = pHead;

	size_t uStringLength = strlen(pTempNode->sData) + 1;
	char* sTempString = new char[uStringLength];
	strcpy_s(sTempString, uStringLength, pTempNode->sData);

	pHead = pHead->pNext;

	delete pTempNode;

	uSize--;
	return sTempString;
}

void TList::Reset() {
	while (pHead) Pop();
	pTail = pIterator = nullptr;
}

TList TList::GetReverseList() {
	TList pTempList;
	TListNode* pTempNode = pHead;

	while(pTempNode->pNext) { 
		pTempList.pHead = pTempNode->pNext;
		pTempList.pHead->pNext = pTempNode;
		pTempNode = pTempNode->pNext;
	}

	return pTempList;
}