#include <iostream>
#include "FileUtils.h"

int main() {
	TFile oFile;

	// Read File
	void* pFile = oFile.OpenFile("Test.txt", "r");

	const unsigned int uBufferSize = 128;
	char sBuffer[uBufferSize];

	unsigned int uCharsRead = static_cast<unsigned int>(oFile.ReadFile(sBuffer, uBufferSize, pFile));
	sBuffer[uCharsRead] = '\0';
	printf("%u characters have been read.\n", uCharsRead);

	printf("%s\n", oFile.CloseFile(pFile) ? "File closed successfully." : "File failed to close.");
	printf("\n");

	// Write File
	pFile = oFile.OpenFile("Test.txt", "a");

	unsigned int uCharsWritten = static_cast<unsigned int>(oFile.WriteFile(sBuffer, uCharsRead, pFile));
	printf("%u characters have been written.\n", uCharsWritten);

	printf("%s\n", oFile.CloseFile(pFile) ? "File closed successfully." : "File failed to close.");

	return 0;
}