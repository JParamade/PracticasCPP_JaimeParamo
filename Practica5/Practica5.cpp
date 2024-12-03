#include <iostream>
#include "FileUtils.h"

int main() {
	void* pFile = OpenFile("Test.txt", "r");

	const unsigned int uBufferSize = 128;
	char sBuffer[uBufferSize];

	unsigned int uReadChars = ReadFile(sBuffer, uBufferSize, pFile);
	printf("%u characters have been read.\n", uReadChars);

	printf("%s\n", CloseFile(pFile) ? "File closed correctly." : "File failed to close.");

	return 0;
}