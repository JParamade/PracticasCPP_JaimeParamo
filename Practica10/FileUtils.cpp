#include <iostream>
#include <string>
#include "FileUtils.h"
#include "TList.h"

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

void* fileOps::GetIntegersInFile(char* _pBuffer, unsigned int _uSize) {
	TList* pStringList = new TList();
	
	unsigned int uAccumulator = 0;
	bool bIsLastNumber = false;

	for (unsigned int uIndex = 0; uIndex < _uSize; uIndex++) {
		if (_pBuffer[uIndex] >= 48 && _pBuffer[uIndex] <= 57) {
			bIsLastNumber = true;
			uAccumulator = uAccumulator * 10 + (_pBuffer[uIndex] - '0');
		}
		else {
			if (_pBuffer[uIndex] == ',') {
				pStringList->Push(std::to_string(uAccumulator).c_str());
				bIsLastNumber = false;
			}
			else if (bIsLastNumber) pStringList->Push(std::to_string(uAccumulator).c_str());
			uAccumulator = 0;
		}
	}

	return pStringList;
}