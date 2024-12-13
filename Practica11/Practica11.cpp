#include <iostream>
#include "TList.h"

int main() {
	TList pStringList1;
	pStringList1.Push("Pa");
	pStringList1.Push("Ti");
	pStringList1.Push("Mi");
	pStringList1.Push("Cola");
	TList pStringList2 = pStringList1.GetReverseList();

	return 0;
}