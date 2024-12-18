#pragma once

enum ImageType {
	NONE,
	PNG, 
	JPG
};

class CImage {
public:
	CImage(int _iResolutionX = 0, int _iResolutionY = 0, int _iColorDepth = 0, ImageType _eType = ImageType::NONE);
	ImageType GetType();
protected:
	int m_iResolutionX, m_iResolutionY;
	int m_iColorDepth;
	ImageType m_eImageType;
};

class CPng : public CImage {
public:
	CPng(int _iResolutionX = 0, int _iResolutionY = 0, int _iColorDepth = 0);
	void DestroyAlpha();
};

class CJpg : public CImage {
public:
	CJpg(int _iResolutionX = 0, int _iResolutionY = 0, int _iColorDepth = 0);
};