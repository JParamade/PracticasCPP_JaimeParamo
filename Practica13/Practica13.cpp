#include <iostream>
#include "ImageUtils.h"
using namespace std;

void DestroyAlpha(CImage* _pImageTable[]) {
	unsigned int uTableSize = sizeof(_pImageTable) / sizeof(CImage);
	
	for (unsigned int uIndex = 0; uIndex < uTableSize; uIndex++) {
		if (_pImageTable[uIndex]->GetType() == ImageType::PNG && _pImageTable[uIndex] != nullptr) static_cast<CPng*>(_pImageTable[uIndex])->DestroyAlpha();
	}
}

int main() {
	CImage* pImageTable[5] = { nullptr } ;
	pImageTable[0] = new CImage();
	pImageTable[1] = new CPng();
	pImageTable[2] = new CJpg();
	pImageTable[3] = new CPng();
	pImageTable[4] = new CImage();

	printf("Destroying alpha channel from PNG images...\n");
	DestroyAlpha(pImageTable);

	for (CImage* pImage : pImageTable) {
		delete pImage;
	}

	return 0;
}