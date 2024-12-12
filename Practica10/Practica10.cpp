#include <iostream>
#include "FileUtils.h"
#include "TList.h"
using namespace fileOps;

int main() {
	void* pFile = OpenFile("Test.txt", "r");

	const unsigned int uBufferSize = 128;
	char sBuffer[uBufferSize];

	unsigned int uCharsRead = static_cast<unsigned int>(ReadFile(sBuffer, uBufferSize, pFile));
	sBuffer[uCharsRead] = '\0';

	TList* pStringList = reinterpret_cast<TList*>(GetStringSum(sBuffer, uCharsRead));
	unsigned int uListSize = pStringList->Size();

	for (unsigned int uIndex = 0; uIndex < uListSize; uIndex++) printf("%s\n", pStringList->Pop());
	printf("\n");

	printf("%s\n", CloseFile(pFile) ? "File closed successfully." : "File failed to close.");

	delete pStringList;

	return 0;
}