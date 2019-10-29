#include <DxLib.h>
#include "ImageMng.h"

ImageMng* ImageMng::s_instance = nullptr;	// é¿ëÃÇÃçÏê¨

ImageMng::ImageMng()
{
}


ImageMng::~ImageMng()
{
}

const VecInt& ImageMng::GetID(const std::string& key)
{
	return ImageMng::GetID(key, key);
}

const VecInt& ImageMng::GetID(const std::string& key, const std::string& fileName)
{
	if (imageMap.find(key) == imageMap.end())
	{
		imageMap[key].resize(1);
		imageMap[key][0] = LoadGraph(fileName.c_str());
	}
	return imageMap[key];
}

const VecInt& ImageMng::GetID(const std::string& key, const std::string& fileName, const Vector2& divSize, const Vector2& divCnt)
{
	if (imageMap.find(key) == imageMap.end())
	{
		imageMap[key].resize(divCnt.x * divCnt.y);
		LoadDivGraph(
			fileName.c_str(),
			divCnt.x * divCnt.y,
			divCnt.x,
			divCnt.y,
			divSize.x,
			divSize.y,
			&imageMap[key][0],
			true
		);
	}
	return imageMap[key];
}
