#include <iostream>
#include "ImageUtils.h"
using namespace std;

void DestroyAlpha(CImage* _pImageTable[], unsigned int _uTableSize) {
	for (unsigned int uIndex = 0; uIndex < _uTableSize; uIndex++) {
		if (_pImageTable[uIndex]->GetType() == ImageType::PNG) static_cast<CPng*>(_pImageTable[uIndex])->DestroyAlpha();
	}
}

int main() {
	CImage* pImageTable[5] = { nullptr } ;
	pImageTable[0] = new CImage();
	pImageTable[1] = new CPng();
	pImageTable[2] = new CJpg();
	pImageTable[3] = new CPng();
	pImageTable[4] = new CImage();

	unsigned int uTableSize = sizeof(pImageTable) / sizeof(pImageTable[0]);

	printf("Destroying alpha channel from PNG images...\n");
	DestroyAlpha(pImageTable, uTableSize);

	for (unsigned int uIndex = 0; uIndex < uTableSize; uIndex++) delete pImageTable[uIndex];

	return 0;
}