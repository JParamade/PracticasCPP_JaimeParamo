#include <iostream>
#include <string>
using namespace std;

void IntegerBytes(unsigned int _uNumber) {
	unsigned char* uChar = reinterpret_cast<unsigned char*> (&_uNumber);

	for (unsigned int uIndex = 0; uIndex < 4; uIndex++) printf("%02hhx\n", *(uChar + uIndex));
}

void GetBiggestInteger(int _iTable[], const unsigned int _uTableSize) {
	int* pTable = _iTable;

	int iBiggestInteger = INT_MIN;

	for (unsigned int uIndex = 0; uIndex < _uTableSize; uIndex++) 
		if (iBiggestInteger < *(pTable + uIndex)) 
			iBiggestInteger = *(pTable + uIndex);

	printf("The biggest integer is %d.", iBiggestInteger);
}

void GetBiggestByte(int _iTable[], const unsigned int _uTableSize) {
	int* pTable = _iTable;

	unsigned char iBiggestByte = CHAR_MIN;

	for (unsigned int uIndex = 0; uIndex < _uTableSize; uIndex++)
		if (iBiggestByte < *(pTable + uIndex))
			iBiggestByte = *(pTable + uIndex);

	printf("The biggest byte is %d.", iBiggestByte);
}

string InvertString(string _sString) {


	return "";
}

int main() {
	unsigned int uNumber = 7;
	IntegerBytes(uNumber);

	int iTable[] = {1, 3, 2, 5, 3, 0xFFFFFFFF, 2};
	const unsigned int iTableSize = sizeof(iTable) / sizeof(int);
	GetBiggestInteger(iTable, iTableSize);
	GetBiggestByte(iTable, iTableSize);

	return 0;
}