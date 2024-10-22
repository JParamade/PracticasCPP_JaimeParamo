#pragma once

namespace file {

	void* OpenFile(const char* _sFileName, const char* _sMode);
	bool CloseFile(void* _pFile);
	unsigned int ReadFile(char* _pBuffer, unsigned int _uSize, void* _pFile);
	// unsigned int WriteFile(char* _pBuffer, unsigned int _uSize, void* _pFile);

}