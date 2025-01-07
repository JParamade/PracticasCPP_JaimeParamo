#define MEMORY_LEAKS_MONITOR

#include "MemoryLeaks.h"

int main() {
	int* pInt = static_cast<int*>(NEW(sizeof(int)));
	*pInt = 15;

	DELETE(pInt);

	float* pFloat = static_cast<float*>(NEW(sizeof(float)));
	*pFloat = 15;

	ReportLeaks();

	DELETE(pFloat);

	return 0;
}