#include "CreateAnim.h"
#include <cocos2d.h>

USING_NS_CC;

void CreateAnim::operator()(std::string unit, std::string act, int num)
{
	// loading plist file

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile(unit + "-" + act + ".plist");

	Animation* animation = Animation::create();
	for (int id = 1; id <= num; id++)
	{
		auto str = __String::createWithFormat((unit + "-" + act + "-%d.png").c_str(), id);
		SpriteFrame* sprite = SpriteFrameCache::getInstance()->getSpriteFrameByName(str->getCString());
		animation->addSpriteFrame(sprite);
	}

	animation->setDelayPerUnit(0.05f);
	animation->setRestoreOriginalFrame(true);

	AnimationCache::getInstance()->addAnimation(animation, (unit + "-" + act));
}
