#pragma once
#include <map>
#include <vector>
#include "VECTOR2.h"

using VecInt = std::vector<int>;

#define lpImageMng ImageMng::GetInstance()
#define IMAGE_ID(KEY) (ImageMng::GetInstance().GetID(KEY))
#define SET_IMAGE_ID(KEY, F_NAME) (ImageMng::GetInstance().GetID(KEY, F_NAME))

class ImageMng
{
public:
	static ImageMng& GetInstance(void)	// アドレスが欲しいのでポインタ渡しor参照渡し
	{
		if (s_instance == nullptr)
		{
			s_instance = new ImageMng();
		}
		return (*s_instance);
	}
	~ImageMng();

	const VecInt& GetID(const std::string& key);	// keyをもとに画像を読み込む、呼び出す
	const VecInt& GetID(
		const std::string& key,
		const std::string& fileName
	);				// fileNameにﾊﾟｽを渡し、keyを設定する
	const VecInt& GetID(
		const std::string& key,
		const std::string& fileName,
		const Vector2& divSize,
		const Vector2& divCnt
	);				// 分割して画像を読み込む

private:
	ImageMng();

	std::map<std::string, VecInt> imageMap;

	static ImageMng* s_instance;		// 自身の実体を持つｲﾝｽﾀﾝｽ変数(ﾎﾟｲﾝﾀ)

};
