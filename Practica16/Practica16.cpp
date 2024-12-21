#include <iostream>
#include "VariableTypes.h"
#include "TList.h"

int main() {
	TList oList;
	
	oList.Push(CMyInt(1));
	oList.Push(CMyInt(1));
	oList.Push(CMyInt(2));
	oList.Push(CMyInt(3));

	oList.Push(CMyString("This"));
	oList.Push(CMyString("is"));
	oList.Push(CMyString("a"));
	oList.Push(CMyString("test."));

	const IComparable* pElement = oList.First();
	printf("First Node: ");

	while (pElement)
	{
		if (const CMyString* pMyString = dynamic_cast<const CMyString*>(pElement)) pMyString->Print();
		else if (const CMyInt* pMyInt = dynamic_cast<const CMyInt*>(pElement))	pMyInt->Print();
		pElement = oList.Next();

		if (pElement) printf("\nNext Node: ");
	}
	printf("\n\n");

	printf("Are element 1 and 2 equal? %s.\n", oList.First()->Equals(*oList.Next()) ? "Yes" : "No");
	oList.Pop();
	printf("Are element 1 and 2 equal? %s.\n", oList.First()->Equals(*oList.Next()) ? "Yes" : "No");

	return 0;
}