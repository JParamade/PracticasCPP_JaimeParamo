#include <iostream>
#include "TList.h"

int main() {
	TList pStringList;
	
	const char* sString1 = "First String";
	const char* sString3 = "Third String";
	const char* sString2 = "Second String";
	const char* sString4 = "Fourth String";

	pStringList.Push(sString1);
	pStringList.Push(sString2);
	pStringList.Push(sString3);
	pStringList.Push(sString4);
	printf("List Size: %d\n", pStringList.Size());

	printf("First Node: %s\n", pStringList.First());
	printf("Next Node: %s\n", pStringList.Next());
	printf("Next Node: %s\n", pStringList.Next());
	printf("Next Node: %s\n", pStringList.Next());

	printf("%s\n", pStringList.Pop());

	printf("First Node: %s\n", pStringList.First());
	printf("Next Node: %s\n", pStringList.Next());
	printf("Next Node: %s\n", pStringList.Next());

	return 0;
}