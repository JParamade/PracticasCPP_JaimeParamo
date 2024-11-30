#include <iostream>
#include <string>

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
	char* pTable = reinterpret_cast<char*>(_iTable);

	char iBiggestByte = CHAR_MIN;
	
	for (unsigned int uIndex = 0u; uIndex < _uTableSize; uIndex++)
		if (iBiggestByte < *(pTable + uIndex))
			iBiggestByte = *(pTable + uIndex);
	
	printf("The biggest byte is %02hhx.\n", iBiggestByte);
}

// const char* InvertString(const char* _sString) {
// 
// 
// 	return "";
// }

int main() {
	unsigned int uNumber = 7;
	IntegerBytes(uNumber);

	int iTable[] = {1, 3, 2, 5, 3, static_cast<int>(0xFFFFFFFF), 2};
	const unsigned int iTableSize = sizeof(iTable) / sizeof(int);
	GetBiggestInteger(iTable, iTableSize);

	for (int iNumber : iTable) IntegerBytes(iNumber);

	GetBiggestByte(iTable, sizeof(iTable));
	
	// const char* sInvertedString = InvertString("");
	// 
	// printf("%s\n", sInvertedString);

	return 0;
}