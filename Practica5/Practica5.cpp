#include "FileUtils.h"
#include <iostream>

int main() {
	void* pFile = file::OpenFile("test.txt", "r");

	const unsigned int uBufferSize = sizeof(pFile);
	char sBuffer[uBufferSize];

	unsigned int uReadChars = file::ReadFile(sBuffer, uBufferSize, pFile);
	printf("%u", uReadChars);

	return 0;
}