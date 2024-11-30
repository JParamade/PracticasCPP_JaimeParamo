#include <iostream>

void IntegerBytes(unsigned int _uNumber) {
	unsigned char* pByte = reinterpret_cast<unsigned char*>(&_uNumber);

	for (unsigned int uIndex = 0u; uIndex < 4u; uIndex++) printf("%02hhx\n", *(pByte + uIndex));
}

void GetBiggestInteger(int _iTable[], const unsigned int _uTableSize) {
	int* pTable = _iTable;

	int iBiggestInteger = INT_MIN;

	for (unsigned int uIndex = 0u; uIndex < _uTableSize; uIndex++)
		if (iBiggestInteger < *(pTable + uIndex))
			iBiggestInteger = *(pTable + uIndex);

	printf("The biggest integer is %d.\n", iBiggestInteger);
}

void GetBiggestByte(int _iTable[], const unsigned int _uTableSize) {
	unsigned char* pTable = reinterpret_cast<unsigned char*>(_iTable);

	unsigned char iBiggestByte = 0;

	for (unsigned int uIndex = 0u; uIndex < _uTableSize; uIndex++)
		if (iBiggestByte < *(pTable + uIndex))
			iBiggestByte = *(pTable + uIndex);

	printf("The biggest byte is %02hhx.\n", iBiggestByte);
}

void InvertString(char* _sString) {
	if (_sString != nullptr) {
		char cAux;
		char* pStringBegin = _sString;
		char* pStringEnd = pStringBegin + strlen(_sString) - 1;

		while (pStringBegin <= pStringEnd) {
			cAux = *pStringBegin;
			*pStringBegin = *pStringEnd;
			*pStringEnd = cAux;

			pStringBegin++;
			pStringEnd--;
		}
	}
}

int main() {
	unsigned int uNumber = 7;
	IntegerBytes(uNumber);

	int iTable[] = { 1, 3, 2, 5, 3, static_cast<int>(0xFFFFFFFF), 2 };
	const unsigned int iTableSize = sizeof(iTable) / sizeof(int);
	GetBiggestInteger(iTable, iTableSize);
	GetBiggestByte(iTable, sizeof(iTable));

	char sInvertedString[] = "This string is getting inverted.";
	InvertString(sInvertedString);
	printf("%s\n", sInvertedString);

	return 0;
}