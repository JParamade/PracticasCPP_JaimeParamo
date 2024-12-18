#include <iostream>

class CNoVirtual {
public:
	void MyFunction() {}
};

class CVirtualBase {
public:
	CVirtualBase() {
		printf("Constructing base...\n");
		MyVirtualFunction();
	}

	virtual void MyVirtualFunction() {
		printf("This is the base virtual function.\n");
	}
};

class CVirtualDerivative : public CVirtualBase {
public:
	CVirtualDerivative() {
		printf("Constructing derivative...\n");
	}

	virtual void MyVirtualFunction() override {
		printf("This is the derivative virtual function.\n");
	}

	void MyNonVirtualFunction() {
		printf("This is the derivative non virtual function.\n");
	}
};

/*********************************************************************************************************************** 
*	Answered Questions:
* 
*	a) The size of the vTable varies depending on the number of virtual functions the class has and the size of a 
*	pointer in the specific architecture. On a 64-bit architecture the size of the pointer is 8 bytes, so a class 
*	with 3 virtual functions will have a vTable with a size of 24 bytes. The same case on a 32-bit architecture 
*	will have a vTable with a size of 12 bytes. 
* 
*	b) vTables are stored on the static data segment, as they are class-specific. They are stored like other global 
*	variables.
* 
*	c) An object is bigger (talking about memory) when it has a vTable. The extra memory is due to the inclusion of a
*	vPointer which points to the specific vTable. Again, the size of this vPointer depends on the architecture (4 bytes
*	on a 32-bit and 8 bytes on a 64-bit).
* 
*	d) Calling a virtual method on the base constructor will execute the method of the base class, ignoring any overrides
*	done. This happens because the vTable is configured for the base class until the constructor of the derivative class 
*	is fully executed.
*	
*	e) The virtual function call has two extra steps, compared to the non virtual function call. These steps are resolving 
*	the vPointer and looking for the specific function on the vTable.
* 
***********************************************************************************************************************/

int main() {
	// Question c)
	printf("The size of the class (wihtout vTable) is %u bytes.\n", static_cast<unsigned int>(sizeof(CNoVirtual)));
	printf("The size of the class (with vTable) is %u bytes.\n", static_cast<unsigned int>(sizeof(CVirtualBase)));
	printf("\n");

	// Question d)
	CVirtualDerivative oVirtual;
	printf("\n");

	// Question e)
	CVirtualBase* pBase = &oVirtual;
	printf("Non virtual function called...\n");
	pBase->MyVirtualFunction();

	printf("Virtual function called...\n");
	pBase->MyVirtualFunction();

	return 0;
}