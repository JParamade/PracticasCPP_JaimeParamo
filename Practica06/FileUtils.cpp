#include <iostream>
#include "FileUtils.h"

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

size_t ReadFile(char* _pBuffer, unsigned int _uSize, void* _pFile) {
	std::FILE* pFile = reinterpret_cast<std::FILE*> (_pFile);

	return fread(_pBuffer, sizeof(char), _uSize, pFile);
}

size_t WriteFile(char* _pBuffer, unsigned int _uSize, void* _pFile) {
	std::FILE* pFile = reinterpret_cast<std::FILE*> (_pFile);

	return fwrite(_pBuffer, sizeof(char), _uSize, pFile);
}

unsigned int CheckStringCount(char* _sString, void* _pFile) {
	std::FILE* pFile = reinterpret_cast<std::FILE*> (_pFile);
	
	
	
	return 0;
}

unsigned int GetIntegerSum(void* _pFile) {
	std::FILE* pFile = reinterpret_cast<std::FILE*> (_pFile);
	
	unsigned int iSum = 0;

	const unsigned int uBufferSize = 128;
	char sBuffer[uBufferSize];
	unsigned int uCharsRead = ReadFile(sBuffer, uBufferSize, _pFile);
	sBuffer[uCharsRead] = '\0';

	unsigned int uAuxNumber = 0;
	bool bIsLastNumber = false;

	for (unsigned int uIndex = 0; uIndex < uCharsRead; uIndex++) {
		if (sBuffer[uIndex] >= 48 && sBuffer[uIndex] <= 57) {
			bIsLastNumber = true;
			uAuxNumber = uAuxNumber * 10 + (sBuffer[uIndex] - '0');
		}
		else if (sBuffer[uIndex] == ',') {
			iSum += uAuxNumber;
			bIsLastNumber = false;
			uAuxNumber = 0;
		}
		else if (bIsLastNumber) {
			iSum += uAuxNumber;
			uAuxNumber = 0;
		}
		else uAuxNumber = 0;
	}

	return iSum;
}