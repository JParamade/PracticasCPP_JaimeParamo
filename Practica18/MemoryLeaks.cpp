#define MEMORY_LEAKS_MONITOR

#include "MemoryLeaks.h"
#include <unordered_map>
#include <sstream>
#include <windows.h>

struct AllocationInfo {
	size_t uSize;
	const char* sFile;
	unsigned int uLine;
};

#ifdef MEMORY_LEAKS_MONITOR

static std::unordered_map<void*, AllocationInfo> mAllocations;

void* MonitorNew(size_t _uSize, const char* _sFile, unsigned int _iLine) {
	void* pPtr = malloc(_uSize);

	if (pPtr) mAllocations[pPtr] = { _uSize, _sFile, _iLine };

	return pPtr;
}

void MonitorDelete(void* _pPtr) {
	auto it = mAllocations.find(_pPtr);

	if (it != mAllocations.end()) mAllocations.erase(it);

	free(_pPtr);
}

void ReportLeaks() {
	for (const auto& pPair : mAllocations) {
		std::ostringstream oss;
		oss << "Memory leak detected:\n"
			<< "  Address: " << pPair.first << "\n"
			<< "  Size: " << pPair.second.uSize << " bytes\n"
			<< "  File: " << pPair.second.sFile << "\n"
			<< "  Line: " << pPair.second.uLine << "\n";
		 
		std::string message = oss.str();
		wchar_t wText[1024];
		size_t convertedChars = 0;
		mbstowcs_s(&convertedChars, wText, sizeof(wText) / sizeof(wchar_t), message.c_str(), _TRUNCATE);
		OutputDebugString(wText);
	}
}

#endif