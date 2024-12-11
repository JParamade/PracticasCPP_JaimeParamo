#include <iostream>
#include "FileUtils.h"

void* fileOps::OpenFile(const char* _sFileName, const char* _sMode) {
	std::FILE* pFile = nullptr;
	fopen_s(&pFile, _sFileName, _sMode);

	return pFile;
}

bool fileOps::CloseFile(void* _pFile) {
	std::FILE* pFile = reinterpret_cast<std::FILE*> (_pFile);
	int iResult = fclose(pFile);

	return iResult == 0;
}

size_t fileOps::ReadFile(char* _pBuffer, unsigned int _uSize, void* _pFile) {
	std::FILE* pFile = reinterpret_cast<std::FILE*> (_pFile);

	return fread(_pBuffer, sizeof(char), _uSize, pFile);
}

size_t fileOps::WriteFile(char* _pBuffer, unsigned int _uSize, void* _pFile) {
	std::FILE* pFile = reinterpret_cast<std::FILE*> (_pFile);

	return fwrite(_pBuffer, sizeof(char), _uSize, pFile);
}