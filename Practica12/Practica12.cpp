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
	oString = "This is a replace test. AAABAAABAAA.";
	printf("\033[1;31mTest F: \033[0m%s\n", oString.ToCString());
	oString = oString.Replace("ABA", "C");
	printf("\t%s\n", oString.ToCString());
	printf("\n");

	// Test G: Path Operations
	oString = "ThisIsATest.exe";
	printf("\033[1;31mTest G: \033[1;36mExtension -> \033[0m%s\n", (oString.ExtractExt()).ToCString());
	printf("\t\033[1;36mName -> \033[0m%s\n\t\033[1;36mReal Path -> \033[0m%s\n", (oString.StripExt()).ToCString(), 
																				  (oString.RealPath()).ToCString());
	printf("\n");
	
	// Test H: File Operations
	printf("\033[1;31mTest H: \033[0m%s\n", (oString.Read("Test.txt")).ToCString());
	oString = " This is a write test.";
	oString.Write("Test.txt");
	printf("\t%s\n", (oString.Read("Test.txt")).ToCString());
	printf("\n");

	// Test I: RValue Operation
	oString = " is an RValue Operation test.";
	printf("\033[1;31mTest I: \033[0m%s\n", ("This" + oString).ToCString());

	return 0;
}