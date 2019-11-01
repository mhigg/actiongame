#include "CreateAnim.h"
#include <cocos2d.h>

USING_NS_CC;

// Create Animation
void CreateAnim::operator()(const std::string& type, const std::string& spName, const std::string& act, const int num)
{
	// loading plist file
	auto frameChache = SpriteFrameCache::getInstance();
	frameChache->addSpriteFramesWithFile("plists/" + type + "/" + spName + "-" + act + ".plist");

	Animation* animation = Animation::create();
	for (int id = 1; id <= num; id++)
	{
		__String* str;
		if (num == 1)
		{
			str = __String::createWithFormat((spName + "-" + act + ".png").c_str(), id);
		}
		else
		{
			str = __String::createWithFormat((spName + "-" + act + "-%d.png").c_str(), id);
		}
		SpriteFrame* sprite = frameChache->getSpriteFrameByName(str->getCString());
		animation->addSpriteFrame(sprite);
	}

	animation->setDelayPerUnit(0.05f);
	animation->setRestoreOriginalFrame(true);

	AnimationCache::getInstance()->addAnimation(animation, (spName + "-" + act));
}
