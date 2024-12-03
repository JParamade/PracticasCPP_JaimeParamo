#include <iostream>
#include "FileUtils.h"

int main() {
	void* pFile = OpenFile("Test.txt", "r");

	const unsigned int uBufferSize = 128;
	char sReadBuffer[uBufferSize];

	unsigned int uCharsRead = ReadFile(sReadBuffer, uBufferSize, pFile);
	printf("%u characters have been read.\n", uCharsRead);

	printf("%s\n", CloseFile(pFile) ? "File closed correctly." : "File failed to close.");

	pFile = OpenFile("Test.txt", "w");

	char sWriteBuffer[] = "Hola";

	unsigned int uCharsWritten = WriteFile(sWriteBuffer, sizeof(sWriteBuffer), pFile);
	printf("%u characters have been written.\n", uCharsWritten);

	printf("%s\n", CloseFile(pFile) ? "File closed correctly." : "File failed to close.");

	return 0;
}