#include <iostream>
#include "TList.h"

int main() {
	TList<int> oIntList;
	
	oIntList.Push(1);
	oIntList.Push(2);
	oIntList.Push(3);
	oIntList.Push(4);

	int* pIntElement = oIntList.First();
	printf("First Node: ");

	while (pIntElement)
	{
		printf("%d", *pIntElement);
		pIntElement = oIntList.Next();

		if (pIntElement) printf("\nNext Node: ");
	}
	printf("\n\n");

	TList<std::string> oStringList;
	
	oStringList.Push("This");
	oStringList.Push("is");
	oStringList.Push("a");
	oStringList.Push("test.");
	
	std::string* pStringElement = oStringList.First();
	printf("First Node: ");
	
	while (pStringElement)
	{
		std::cout << *pStringElement;
		pStringElement = oStringList.Next();
	
		if (pStringElement) printf("\nNext Node: ");
	}
	printf("\n");

	return 0;
}