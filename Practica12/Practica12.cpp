/********************
   WORK IN PROGRESS
********************/

/********************
   12. (OPCIONAL) Operadores:
		a. Dada la clase “CString” declarada en el fichero “String.h” implementar en un
		fichero .cpp toda la funcionalidad de dicha clase.
		b. Mejora: Implementar funcionalidad para que se puedan realizar operaciones
		de tipo:
			i. CString str(“hola ”);
			ii. CString str2 = “Hola“ + str + “caracola”
********************/

#include <iostream>
#include "string.h"

int main() {
	// Test A: Append
	CString oString("This");
	printf("\033[1;31mTest A: \033[0m%s\n", (oString + " is an append test.").ToCString());
	printf("\n");

	// Test B: Trim
	oString = "   This is a trim test.   ";
	printf("\033[1;31mTest B: \033[1;36mLength Before Trim -> \033[0m%d\n", oString.Length());
	oString = (oString.Trim()).ToCString();
	printf("\t\033[1;36mString Trimmed -> \033[0m%s\n\t\033[1;36mLength After Trim -> \033[0m%d\n", oString.ToCString(), oString.Length());
	printf("\n");

	// Test C: Upper-Lower Case
	oString = "This is an upper case test.";
	printf("\033[1;31mTest C: \033[0m%s\n", (oString.ToUpper()).ToCString());
	oString = "THIS IS A LOWER CASE TEST.";
	printf("\033[1;31m	\033[0m%s\n", (oString.ToLower()).ToCString());
	printf("\n");

	// Test D: L-RSet
	oString = "This is a LRSet test.";
	printf("\033[1;31mTest D: \033[0m%s\n", ((oString.LSet(25, '_')).RSet(29, '_')).ToCString());
	printf("\n");

	// Test E: Left-Right-Mid
	oString = "This is a test.";
	printf("\033[1;31mTest E: \033[0m%s\n", (oString.Left(4)).ToCString());
	printf("\t%s\n", (oString.Mid(5, 2)).ToCString());
	printf("\t%s\n", (oString.Mid(8, 1)).ToCString());
	printf("\t%s\n", (oString.Right(5)).ToCString());
	printf("\n");

	// Test F: Replace

	// Test G: Path Operations

	// Test H: File Operations
	printf("\033[1;31mTest F: \033[0m%s\n", (oString.Read("Test.txt")).ToCString());
	oString = " This is a write test.";
	oString.Write("Test.txt");

	return 0;
}