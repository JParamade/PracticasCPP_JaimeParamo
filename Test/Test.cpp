#include <iostream>

struct CBool {
	bool bBool1;
	bool bBool2;
	bool bBool3;
	bool bBool4;
};

struct CInt {
	int iNumber;
};

int main() {
	printf("%u\n", static_cast<unsigned int>(sizeof(CBool)));
	printf("%u\n", static_cast<unsigned int>(sizeof(CInt)));
}