#include "FileUtils.h"
#include <iostream>

void CFile::Open() {
	printf("Opening file...\n");
}

void CFile::Close() {
	printf("Closing file...\n");
}

void CFile::Read() {
	printf("Reading file...\n");
}

void CFile::Write(const char* _sData) {
	printf("Writing \"%s\" in file...\n", _sData);
}

void CCom::Open() {
	printf("Opening COM serial port...\n");
}

void CCom::Close() {
	printf("Closing COM serial port...\n");
}

void CCom::Read() {
	printf("Reading COM serial port...\n");
}

void CCom::Write(const char* _sData) {
	printf("Writing \"%s\" in COM serial port...\n", _sData);
}

void CTcp::Open() {
	printf("Opening TCP conection...\n");
}

void CTcp::Close() {
	printf("Closing TCP conection...\n");
}

void CTcp::Read() {
	printf("Reading TCP conection...\n");
}

void CTcp::Write(const char* _sData) {
	printf("Writing \"%s\" in TCP conection...\n", _sData);
}