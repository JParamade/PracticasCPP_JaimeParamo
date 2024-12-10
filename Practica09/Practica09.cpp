#include <iostream>
#include "TList.h"

int main() {
	TList pStringList;
	
	const char* sString1 = "First String";
	const char* sString3 = "Third String";
	const char* sString2 = "Second String";
	const char* sString4 = "Fourth String";

	pStringList.Push(sString1);
	printf("%d\n", pStringList.Size());
	pStringList.Push(sString2);
	printf("%d\n", pStringList.Size());
	pStringList.Push(sString3);
	printf("%d\n", pStringList.Size());
	pStringList.Push(sString4);
	printf("%d\n", pStringList.Size());
	printf("%s\n", pStringList.First());
	printf("%s\n", pStringList.Next());
	printf("%s\n", pStringList.Next());
	printf("%s\n", pStringList.Next());
	printf("%s\n", pStringList.Next());

	return 0;
}