#include <iostream>
#include "TList.h"

int main() {
	TList pStringList1;

	pStringList1.Push("One");
	pStringList1.Push("Two");
	pStringList1.Push("Three");
	pStringList1.Push("Four");

	printf("%s\n", pStringList1.First());
	printf("%s\n", pStringList1.Next());
	printf("%s\n", pStringList1.Next());
	printf("%s\n", pStringList1.Next());
	printf("\n");

	TList pStringList2 = pStringList1.GetReverseList();

	printf("%s\n", pStringList2.First());
	printf("%s\n", pStringList2.Next());
	printf("%s\n", pStringList2.Next());
	printf("%s\n", pStringList2.Next());

	return 0;
}