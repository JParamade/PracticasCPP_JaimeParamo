#include <iostream>
#include "FileUtils.h"

int main() {
	// Read File
	void* pFile = OpenFile("Test.txt", "r");

	const unsigned int uBufferSize = 128;
	char sBuffer[uBufferSize];

	unsigned int uCharsRead = static_cast<unsigned int>(ReadFile(sBuffer, uBufferSize, pFile));
	sBuffer[uCharsRead] = '\0';
	printf("%u characters have been read.\n", uCharsRead);

	printf("%s\n", CloseFile(pFile) ? "File closed correctly." : "File failed to close.");
	
	// Write File
	pFile = OpenFile("Test.txt", "a");

	unsigned int uCharsWritten = static_cast<unsigned int>(WriteFile(sBuffer, uCharsRead, pFile));
	printf("%u characters have been written.\n", uCharsWritten);

	printf("%s\n", CloseFile(pFile) ? "File closed correctly." : "File failed to close.");

	return 0;
}