#pragma once

enum ImageType {
	NONE,
	PNG, 
	JPG
};

class CImage {
public:
	CImage(ImageType _eImageType = ImageType::NONE);
	~CImage();

protected:
	int m_iResolutionX, m_iResolutionY;
	int m_iColorDepth;
	ImageType eImageType;
};

class CPng : public CImage {
	void DestroyAlpha();
};

class CJpg : public CImage {

};