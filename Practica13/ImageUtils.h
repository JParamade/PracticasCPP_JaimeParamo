#pragma once

enum ImageType {
	PNG, 
	JPG
};

class CImage {
public:
	CImage();
	~CImage();

private:
	int m_iResolutionX;
	int m_iResolutionY;
	int m_iColorDepth;
};

class CPng : public CImage{

};

class CJpg : public CImage {

};