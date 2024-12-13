#include <iostream>
#include "TList.h"

int main() {
	TList pStringList1;
	pStringList1.Push("Pa");
	pStringList1.Push("Ti");
	pStringList1.Push("Mi");
	pStringList1.Push("Cola");
	TList pStringList2 = pStringList1.GetReverseList();

	printf("%s %s %s %s\n", pStringList1.First(), pStringList1.Next(), pStringList1.Next(), pStringList1.Next());
	printf("%s %s %s %s\n", pStringList2.First(), pStringList2.Next(), pStringList2.Next(), pStringList2.Next());

	return 0;
}