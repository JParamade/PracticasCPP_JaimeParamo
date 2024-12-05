#include <iostream>

const char* sStringTable[]{
    "First String",
    "Second String",
    "Third String",
    "Fourth String"
};
const unsigned int uTableSize = sizeof(sStringTable) / sizeof(const char*);

const char* GetString(unsigned int _uIndex) {
    return _uIndex < uTableSize ? sStringTable[_uIndex] : "Index out of range.";
}

const char* GetInvertedString(unsigned int _uIndex) {
    const char* pString = sStringTable[_uIndex];

    if (pString == nullptr) return nullptr;

    const unsigned int uStringSize = static_cast<const unsigned int>(strlen(pString));

    char* sInvertedString = new char[uStringSize + 1];
    sInvertedString[uStringSize] = '\0';

    for (unsigned int uIndex = 0; uIndex < uStringSize; uIndex++) sInvertedString[uIndex] = pString[uStringSize - (uIndex + 1)];

    return sInvertedString;
}

int main() {
    unsigned int uIndex = 1;
    const char* sTableString = GetString(uIndex);
    printf("%s\n", sTableString);

    const char* sTableStringInverted = GetInvertedString(uIndex);
    printf("%s\n", sTableStringInverted);
    delete[] sTableStringInverted;
}