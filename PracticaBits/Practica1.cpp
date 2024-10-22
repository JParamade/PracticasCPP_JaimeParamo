#include <iostream>
#include <string>

#define MASK_BULLETS 0x00FF0000
#define MASK4 0xF
#define MASK_INFINITEBULLETS 0x00000002

unsigned int GetBulletNumber(unsigned int _uValue) {
	unsigned int uBulletNumber = 0u;

	uBulletNumber = _uValue & MASK_BULLETS;

	uBulletNumber = uBulletNumber >> 16;

	return uBulletNumber;
}

void AddBullets(unsigned int _uValue, unsigned int _uBullets) {
	unsigned int uBulletNumber = GetBulletNumber(_uValue);

	uBulletNumber += _uBullets;
	

}

bool AreInfiniteBulletsActive(unsigned int _uValue) {
	bool bIsActivated = false;

	bIsActivated = _uValue & MASK_INFINITEBULLETS;
	
	bIsActivated = bIsActivated >> 1;
	
	return bIsActivated;
}

void ActivateInfiniteBullets(unsigned int _uValue) {
	_uValue |= MASK_INFINITEBULLETS;
}

int main() {
	unsigned int uMyInfo = 0x890D700C;
	
	std::cout << "You have " << GetBulletNumber(uMyInfo) << " bullets.\n";
	
	AddBullets(uMyInfo, 20);
	std::cout << "You have " << GetBulletNumber(uMyInfo) << " bullets.\n";

	std::string sInfiniteBullets = AreInfiniteBulletsActive(uMyInfo) ? "Infinite bullets are active." : "Infinite bullets are not active.";
	std::cout << sInfiniteBullets << '\n';

	ActivateInfiniteBullets(uMyInfo);
	sInfiniteBullets = AreInfiniteBulletsActive(uMyInfo) ? "Infinite bullets are active." : "Infinite bullets are not active.";
	std::cout << sInfiniteBullets << '\n';

	return 0;
}