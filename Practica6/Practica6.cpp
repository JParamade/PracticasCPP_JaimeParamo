#include <iostream>
#include "FileUtils.h"

int main() {
	void* pFile = OpenFile("Test.txt", "r");
	
	// const char* sString = "Test";
	// CheckStringCount(sString, pFile);
	
	printf("Integers in file sum %u.", GetIntegerSum(pFile));

	return 0;
}