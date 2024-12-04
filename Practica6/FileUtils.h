#pragma once

void* OpenFile(const char* _sFileName, const char* _sMode);
bool CloseFile(void* _pFile);
size_t ReadFile(char* _pBuffer, unsigned int _uSize, void* _pFile);
size_t WriteFile(char* _pBuffer, unsigned int _uSize, void* _pFile);

unsigned int CheckStringCount(char* _sString, void* _pFile);
unsigned int GetIntegerSum(void* _pFile);