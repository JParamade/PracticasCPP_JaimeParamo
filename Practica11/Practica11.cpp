#include <iostream>
#include "TList.h"

int main() {
	TList pStringList1;
	pStringList1.Push("Hola");
	TList pStringList2 = pStringList1;

	printf("%d\n", pStringList1.Size());
	printf("%d\n", pStringList2.Size());

	return 0;
}