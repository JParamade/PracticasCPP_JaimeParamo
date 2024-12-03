#include "FileUtils.h"
#include <cstdio>

void* OpenFile(const char* _sFileName, const char* _sMode) {
	std::FILE* pFile = nullptr;
	fopen_s(&pFile, _sFileName, _sMode);

	return pFile;
}

bool CloseFile(void* _pFile) {
	std::FILE* pFile = reinterpret_cast<std::FILE*> (_pFile);
	int iResult = fclose(pFile);

	return iResult == 0;
}

unsigned int ReadFile(char* _pBuffer, unsigned int _uSize, void* _pFile) {
	std::FILE* pFile = reinterpret_cast<std::FILE*> (_pFile);

	unsigned int uCharsRead = static_cast<unsigned int>(fread(_pBuffer, sizeof(char), _uSize, pFile));

	return uCharsRead;
}

// unsigned int WriteFile(char* _pBuffer, unsigned int _uSize, void* _pFile) {
// 	
// 	
// 	return 0;
// }