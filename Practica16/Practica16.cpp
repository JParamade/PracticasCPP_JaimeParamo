#include <iostream>
#include "VariableTypes.h"
#include "TList.h"

int main() {
	TList oList;
	
	CMyInt oNumber(1);
	CMyInt oNumber2(2);
	CMyInt oNumber3(3);
	CMyInt oNumber4(3);

	CMyString oString("This");
	CMyString oString2("is");
	CMyString oString3("a");
	CMyString oString4("test.");

	oList.Push(oNumber);
	oList.Push(oNumber2);
	oList.Push(oNumber3);
	oList.Push(oNumber4);
	oList.Push(oString);
	oList.Push(oString2);
	oList.Push(oString3);
	oList.Push(oString4);

	printf("First Node: \"%s\".\n", oList.First());
	printf("Next Node: \"%s\".\n", oList.Next());
	printf("Next Node: \"%s\".\n", oList.Next());
	printf("Next Node: \"%s\".\n", oList.Next());
	printf("\n");

	return 0;
}