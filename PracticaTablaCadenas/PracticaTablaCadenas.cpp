#include <iostream>
#include <string>

const char* sStringTable[]{
	"First String",
	"Second String",
	"Third String",
	"Fourth String"
};
const unsigned int uTableSize = sizeof(sStringTable) / sizeof(const char*);

const char* GetString(unsigned int _uIndex) { 
	if (_uIndex < uTableSize) return sStringTable[_uIndex];
	else return "Index out of range.";
}

void GetStringInverted(unsigned int _uIndex, char* _pBuffer, unsigned int _uBufferSize) {
	const char* pString = sStringTable[_uIndex];

	if (pString != nullptr) {
		const unsigned int uStringSize = strlen(pString);
		char* pInvertedString = new char[uStringSize + 1];

		// Check buffer size.

		pInvertedString[uStringSize] = '\0';

		for (unsigned int uIndex = 0; uIndex < uStringSize; uIndex++) {

		}
	}
}

int main() {
	printf("%s\n", GetString(5));

	char* pString = new char[128];
	pString[0] = '\0';
	GetStringInverted(0, pString, 128);
	printf("%s\n", pString);
	delete[] pString;
}