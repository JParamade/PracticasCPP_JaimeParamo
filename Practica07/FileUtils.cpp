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

unsigned int fileFuncs::CheckStringCount(char* _pBuffer, unsigned int _uSize, const char* _sString, void* _pFile) {
	std::FILE* pFile = reinterpret_cast<std::FILE*> (_pFile);
	
	unsigned int uStringLength = strlen(_sString) - 1;
	unsigned int uCurrentChar = 0;
	unsigned int uCount = 0;

	for (unsigned int uIndex = 0; uIndex < _uSize; uIndex++) {
		if (*(_sString + uCurrentChar) == _pBuffer[uIndex] && uCurrentChar < uStringLength) uCurrentChar++;
		else if (uCurrentChar == uStringLength) {
			uCount++;
			uCurrentChar = 0;
		}
		else uCurrentChar = 0;
	}

	return uCount;
}

unsigned int fileFuncs::GetIntegerSum(char* _pBuffer, unsigned int _uSize, void* _pFile) {
	std::FILE* pFile = reinterpret_cast<std::FILE*> (_pFile);
	
	unsigned int uSum = 0;
	unsigned int uAccumulator = 0;
	bool bIsLastNumber = false;

	for (unsigned int uIndex = 0; uIndex < _uSize; uIndex++) {
		if (_pBuffer[uIndex] >= 48 && _pBuffer[uIndex] <= 57) {
			bIsLastNumber = true;
			uAccumulator = uAccumulator * 10 + (_pBuffer[uIndex] - '0');
		}
		else if (_pBuffer[uIndex] == ',') {
			uSum += uAccumulator;
			bIsLastNumber = false;
			uAccumulator = 0;
		}
		else if (bIsLastNumber) {
			uSum += uAccumulator;
			uAccumulator = 0;
		}
		else uAccumulator = 0;
	}

	return uSum;
}