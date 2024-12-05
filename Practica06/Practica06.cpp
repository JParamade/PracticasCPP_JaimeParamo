#include <iostream>
#include "FileUtils.h"

int main() {
	void* pFile = OpenFile("Test.txt", "r");
	
	// const char* sString = "Test";
	// CheckStringCount(sString, pFile);
	
	printf("Integers in file sum %u.\n", GetIntegerSum(pFile));

	printf("%s\n", CloseFile(pFile) ? "File closed correctly." : "File failed to close.");

	return 0;
}