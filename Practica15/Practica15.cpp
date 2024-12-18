#include "FileUtils.h"
#include <iostream>

void StreamTest(CStream* _pStream) {
	_pStream->Open();
	_pStream->Close();
	_pStream->Read();
	_pStream->Write("This is a test.");
}

int main() {
	CFile oFile;
	CCom oCom;
	CTcp oTcp;

	printf("Testing file...\n");
	StreamTest(&oFile);
	printf("\n");

	printf("Testing COM serial port...\n");
	StreamTest(&oCom);
	printf("\n");
	
	printf("Testing TCP connection...\n");
	StreamTest(&oTcp);
	
	return 0;
}