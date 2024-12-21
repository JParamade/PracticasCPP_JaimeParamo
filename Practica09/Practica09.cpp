#include <iostream>
#include "TList.h"

int main() {
	TList oStringList;
	
	const char* sString1 = "First String";
	const char* sString3 = "Third String";
	const char* sString2 = "Second String";
	const char* sString4 = "Fourth String";

	oStringList.Push(sString1);
	oStringList.Push(sString2);
	oStringList.Push(sString3);
	oStringList.Push(sString4);
	printf("List Size: %d\n", oStringList.Size());
	printf("\n");

	printf("First Node: \"%s\".\n", oStringList.First());
	printf("Next Node: \"%s\".\n", oStringList.Next());
	printf("Next Node: \"%s\".\n", oStringList.Next());
	printf("Next Node: \"%s\".\n", oStringList.Next());
	printf("\n");

	printf("Popped Node: \"%s\".\n", oStringList.Pop());
	printf("\n");

	printf("First Node: \"%s\".\n", oStringList.First());
	printf("Next Node: \"%s\".\n", oStringList.Next());
	printf("Next Node: \"%s\".\n", oStringList.Next());
	printf("\n");

	oStringList.Reset();
	printf("List Reseted.\n");
	printf("List Size: %d\n", oStringList.Size());
	printf("\n");

	oStringList.Push(sString1);
	printf("List Size: %d\n", oStringList.Size());
	printf("First Node: \"%s\".\n", oStringList.First());

	return 0;
}