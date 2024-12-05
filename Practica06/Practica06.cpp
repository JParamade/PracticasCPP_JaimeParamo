#include <iostream>
#include "FileUtils.h"

int main() {
	void* pFile = OpenFile("Test.txt", "r");
	
	const unsigned int uBufferSize = 128;
	char sBuffer[uBufferSize];
	unsigned int uCharsRead = ReadFile(sBuffer, uBufferSize, pFile);
	sBuffer[uCharsRead] = '\0';

	const char* sString = "Test";
	
	printf("The word \"%s\" appears %u times in the file.\n", sString, CheckStringCount(sBuffer, uCharsRead, sString, pFile));
	printf("Integers in file sum %u.\n", GetIntegerSum(sBuffer, uCharsRead, pFile));

	printf("%s\n", CloseFile(pFile) ? "File closed successfully." : "File failed to close.");

	return 0;
}