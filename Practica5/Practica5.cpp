#include <iostream>
#include "FileUtils.h"

int main() {
	// Read File
	void* pFile = OpenFile("Test.txt", "r");

	const unsigned int uBufferSize = 128;
	char sReadBuffer[uBufferSize];

	unsigned int uCharsRead = static_cast<unsigned int>(ReadFile(sReadBuffer, uBufferSize, pFile));
	printf("%u characters have been read.\n", uCharsRead);

	printf("%s\n", CloseFile(pFile) ? "File closed correctly." : "File failed to close.");

	// Write File
	pFile = OpenFile("Test.txt", "a");

	char sWriteBuffer[] = "Hola";

	unsigned int uCharsWritten = static_cast<unsigned int>(WriteFile(sWriteBuffer, sizeof(sWriteBuffer), pFile));
	printf("%u characters have been written.\n", uCharsWritten);

	printf("%s\n", CloseFile(pFile) ? "File closed correctly." : "File failed to close.");

	return 0;
}