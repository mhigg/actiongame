#pragma once
#include <cocos2d.h>
#include <map>

#define lpAnimMng AnimationMng::GetInstance()

struct AnimData
{
	std::string spType;		// ���ײĂ̑���(player/enemy)
	std::string spName;		// ���ײĂ̖��O
	std::string animName;	// ��Ұ��݂̖��O
	int frame;				// ��Ұ��݂��ڰѐ�
	float delay;			// ��Ұ��݂�1�ڰт��Ƃ̊Ԋu
	bool restore;			// ��Ұ��݂��I�������Ƃ��ŏ����ڰтɖ߂邩�ǂ���
};

class AnimationMng
{
public:
	static AnimationMng& GetInstance(void)
	{
		if (s_instance == nullptr)
		{
			 s_instance = new AnimationMng();
		}
		return (*s_instance);
	}

	void AddAnimation(AnimData& animData);
	void SetAnimation(cocos2d::Sprite& sprite, const std::string& spriteName, const std::string& animName);

private:
	AnimationMng();
	~AnimationMng();

	static AnimationMng* s_instance;
};

