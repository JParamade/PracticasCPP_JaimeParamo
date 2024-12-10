#include <iostream>
#include "FileUtils.h"

int main() {
	void* pFile = OpenFile("Test.txt", "r");
	
	const unsigned int uBufferSize = 128;
	char sBuffer[uBufferSize];
	unsigned int uCharsRead = static_cast<unsigned int>(ReadFile(sBuffer, uBufferSize, pFile));
	sBuffer[uCharsRead] = '\0';

	const char* sString = "test";
	
	printf("The string \"%s\" appears %u times in the file.\n", sString, CheckStringCount(sBuffer, uCharsRead, sString));
	printf("Integers in file sum %u.\n", GetIntegerSum(sBuffer, uCharsRead));

	printf("%s\n", CloseFile(pFile) ? "File closed successfully." : "File failed to close.");

	return 0;
}