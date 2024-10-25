#include <iostream>

#define MASK_BULLETS 0x00FF0000
#define MASK4 0xF
#define MASK_INFINITEBULLETS 0x00000002

unsigned int GetBulletNumber(unsigned int _uValue) {
	unsigned int uBulletNumber = 0u;

	uBulletNumber = _uValue & MASK_BULLETS;

	uBulletNumber = uBulletNumber >> 16;

	return uBulletNumber;
}

void AddBullets(unsigned int &_uValue, unsigned int _uBullets) {
	unsigned int uBulletNumber = GetBulletNumber(_uValue);

	uBulletNumber += _uBullets;
	if (uBulletNumber > UCHAR_MAX) _uBullets = UCHAR_MAX;
	
	_uValue &= ~MASK_BULLETS;

	uBulletNumber = (uBulletNumber << 16);
}

bool AreInfiniteBulletsActive(unsigned int _uValue) {
	bool bIsActivated = false;

	bIsActivated = _uValue & MASK_INFINITEBULLETS;
	
	return bIsActivated;
}

void ActivateInfiniteBullets(unsigned int &_uValue) {
	_uValue |= MASK_INFINITEBULLETS;
}

int main() {
	unsigned int uMyInfo = 0x890D700C;
	
	printf("You have %u bullets.\n", GetBulletNumber(uMyInfo));
	
	AddBullets(uMyInfo, 20);
	printf("You have %u bullets.\n", GetBulletNumber(uMyInfo));

	const char* sInfiniteBullets = AreInfiniteBulletsActive(uMyInfo) ? "Infinite bullets are active." : "Infinite bullets are not active.";
	printf("%s\n", sInfiniteBullets);

	ActivateInfiniteBullets(uMyInfo);
	sInfiniteBullets = AreInfiniteBulletsActive(uMyInfo) ? "Infinite bullets are active." : "Infinite bullets are not active.";
	printf("%s\n", sInfiniteBullets);

	return 0; 
}