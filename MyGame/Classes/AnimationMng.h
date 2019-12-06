#pragma once
#include <cocos2d.h>
#include <map>

#define lpAnimMng AnimationMng::GetInstance()

struct AnimData
{
	std::string spType;		// ½Ìß×²Ä‚Ì‘®«(player/enemy)
	std::string spName;		// ½Ìß×²Ä‚Ì–¼‘O
	std::string animName;	// ±ÆÒ°¼®İ‚Ì–¼‘O
	int frame;				// ±ÆÒ°¼®İ‚ÌÌÚ°Ñ”
	float delay;			// ±ÆÒ°¼®İ‚Ì1ÌÚ°Ñ‚²‚Æ‚ÌŠÔŠu
	bool restore;			// ±ÆÒ°¼®İ‚ªI—¹‚µ‚½‚Æ‚«Å‰‚ÌÌÚ°Ñ‚É–ß‚é‚©‚Ç‚¤‚©
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

