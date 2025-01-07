#pragma once

#ifdef MEMORY_LEAKS_MONITOR

#define NEW(_SIZE) MonitorNew(_SIZE, __FILE__, __LINE__)
#define NEW_ARRAY(_SIZE) MonitorNew(_SIZE, __FILE__, __LINE__)
#define DELETE(_PTR) MonitorDelete(_PTR)
#define DELETE_ARRAY(_PTR) MonitorDelete(_PTR)

void* MonitorNew(size_t _uSize, const char* _sFile, unsigned int _iLine);
void MonitorDelete(void* _pPtr);
void ReportLeaks();

#else

#define NEW(_SIZE) new 
#define NEW_ARRAY(_TYPE, _SIZE) new _TYPE[_SIZE]
#define DELETE(_PTR) delete _PTR
#define DELETE_ARRAY(_PTR) delete[] _PTR

#endif

