#include <iostream>
#include "ImageUtils.h"

CImage::CImage(int _iResolutionX, int _iResolutionY, int _iColorDepth, ImageType _eType)
	: m_iResolutionX(_iResolutionX)
	, m_iResolutionY(_iResolutionY)
	, m_iColorDepth(_iColorDepth)
	, m_eImageType(_eType)
{}

ImageType CImage::GetType() {
	return m_eImageType;
}

CPng::CPng(int _iResolutionX, int _iResolutionY, int _iColorDepth)
	: CImage(_iResolutionX, _iResolutionY, _iColorDepth, ImageType::PNG)
{}

void CPng::DestroyAlpha() {
	printf("Alpha destroyed.\n");
}

CJpg::CJpg(int _iResolutionX, int _iResolutionY, int _iColorDepth)
	: CImage(_iResolutionX, _iResolutionY, _iColorDepth, ImageType::JPG)
{}