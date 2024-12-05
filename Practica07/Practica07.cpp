#include <iostream>
#include "FileUtils.h"
using namespace fileOps;
using namespace fileFuncs;

int main() {
	// Read File
	void* pFile = OpenFile("TestP5.txt", "r");

	const unsigned int uBufferSize = 128;
	char sBuffer[uBufferSize];

	unsigned int uCharsRead = static_cast<unsigned int>(ReadFile(sBuffer, uBufferSize, pFile));
	sBuffer[uCharsRead] = '\0';
	printf("%u characters have been read.\n", uCharsRead);

	printf("%s\n", CloseFile(pFile) ? "File closed successfully." : "File failed to close.");
	printf("\n");

	// Write File
	pFile = OpenFile("TestP5.txt", "a");

	unsigned int uCharsWritten = static_cast<unsigned int>(WriteFile(sBuffer, uCharsRead, pFile));
	printf("%u characters have been written.\n", uCharsWritten);

	printf("%s\n", CloseFile(pFile) ? "File closed successfully." : "File failed to close.");
	printf("\n");
	
	// Check number of times a string appears in file and calculate the sum of contained integers.
	pFile = OpenFile("TestP6.txt", "r");

	char sBuffer2[uBufferSize];
	uCharsRead = ReadFile(sBuffer2, uBufferSize, pFile);
	sBuffer2[uCharsRead] = '\0';

	const char* sString = "test";

	printf("The string \"%s\" appears %u times in the file.\n", sString, CheckStringCount(sBuffer2, uCharsRead, sString, pFile));
	printf("Integers in file sum %u.\n", GetIntegerSum(sBuffer2, uCharsRead, pFile));

	printf("%s\n", CloseFile(pFile) ? "File closed successfully." : "File failed to close.");

	return 0;
}