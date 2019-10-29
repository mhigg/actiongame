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
	static ImageMng& GetInstance(void)	// �A�h���X���~�����̂Ń|�C���^�n��or�Q�Ɠn��
	{
		if (s_instance == nullptr)
		{
			s_instance = new ImageMng();
		}
		return (*s_instance);
	}
	~ImageMng();

	const VecInt& GetID(const std::string& key);	// key�����Ƃɉ摜��ǂݍ��ށA�Ăяo��
	const VecInt& GetID(
		const std::string& key,
		const std::string& fileName
	);				// fileName���߽��n���Akey��ݒ肷��
	const VecInt& GetID(
		const std::string& key,
		const std::string& fileName,
		const Vector2& divSize,
		const Vector2& divCnt
	);				// �������ĉ摜��ǂݍ���

private:
	ImageMng();

	std::map<std::string, VecInt> imageMap;

	static ImageMng* s_instance;		// ���g�̎��̂����²ݽ�ݽ�ϐ�(�߲��)

};
