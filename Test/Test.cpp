#include <iostream>

struct SBool {
	bool bBool1;
	bool bBool2;
	bool bBool3;
	bool bBool4;
};

struct SInt {
	int iNumber;
};

int main() {
	printf("%u\n", static_cast<unsigned int>(sizeof(SBool)));
	printf("%u\n", static_cast<unsigned int>(sizeof(SInt)));
}