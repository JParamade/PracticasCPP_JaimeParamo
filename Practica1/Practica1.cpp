#include <iostream>

#define MASK_BULLETS 0x00FF0000
#define MASK_INFINITE_BULLETS 0x00000002

unsigned int GetBulletNumber(unsigned int _uValue) { 
	return (_uValue & MASK_BULLETS) >> 16; 
}

void AddBullets(unsigned int &_uValue, unsigned int _uBullets) {
	unsigned int uBulletNumber = GetBulletNumber(_uValue);

	uBulletNumber += _uBullets;
	if (uBulletNumber > UCHAR_MAX) uBulletNumber = UCHAR_MAX;
	
	_uValue &= ~MASK_BULLETS;
	
	_uValue = uBulletNumber << 16;
}

bool AreInfiniteBulletsActive(unsigned int _uValue) { 
	return _uValue & MASK_INFINITE_BULLETS; 
}

void ActivateInfiniteBullets(unsigned int& _uValue) { 
	_uValue |= MASK_INFINITE_BULLETS; 
}

int main() {
	unsigned int uMyInfo = 0x890D700C;
	
	printf("You have %u bullets.\n", GetBulletNumber(uMyInfo));
	
	AddBullets(uMyInfo, 50);
	printf("You have %u bullets.\n", GetBulletNumber(uMyInfo));

	const char* sInfiniteBullets = AreInfiniteBulletsActive(uMyInfo) ? "Infinite bullets are active." : "Infinite bullets are not active.";
	printf("%s\n", sInfiniteBullets);

	ActivateInfiniteBullets(uMyInfo);
	sInfiniteBullets = AreInfiniteBulletsActive(uMyInfo) ? "Infinite bullets are active." : "Infinite bullets are not active.";
	printf("%s\n", sInfiniteBullets);

	return 0; 
}