#include <iostream>

class CNoVirtual {
public:
	int m_iX;
	void MyFunction();
};

class CVirtual {
public:
	int m_iX;
	virtual void MyFunction();
};

/* 
*	Practice 14 Answered Questions:
*	a) The size of the vtable is the same for  
* 
* 
* 
*/

int main() {
	printf("The size of the class with no virtual functions is %d bytes.\n", static_cast<int>(sizeof(CNoVirtual)));
	printf("The size of the class with virtual functions is %d bytes.\n", static_cast<int>(sizeof(CVirtual)));



}