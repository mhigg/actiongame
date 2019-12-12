#include "AnimationMng.h"
#include <unit/Player.h>

USING_NS_CC;

AnimationMng* AnimationMng::s_instance = nullptr;

void AnimationMng::AddAnimation(const AnimData& animData)
{
	auto animKey = (animData.spName + "-" + animData.animName);
	// loading plist file
	auto frameChache = SpriteFrameCache::getInstance();
	frameChache->addSpriteFramesWithFile("plists/" + animData.spType + "/" + animKey + ".plist");

	Animation* animation = Animation::create();
	for (int id = 1; id <= animData.frame; id++)
	{
		__String* str;
		if (animData.frame == 1)
		{
			str = __String::createWithFormat((animKey + ".png").c_str(), id);
		}
		else
		{
			str = __String::createWithFormat((animKey + "-%d.png").c_str(), id);
		}
		SpriteFrame* sprite = frameChache->getSpriteFrameByName(str->getCString());
		animation->addSpriteFrame(sprite);
	}

	animation->setDelayPerUnit(animData.delay);
	animation->setRestoreOriginalFrame(animData.restore);

	AnimationCache::getInstance()->addAnimation(animation, animKey);
}

void AnimationMng::SetAnimation(cocos2d::Sprite& sprite, const std::string& spriteName, const std::string& animName)
{
	auto cache = AnimationCache::getInstance()->getAnimation(spriteName + "-" + animName);
	auto idle = RepeatForever::create(Animate::create(cache));
	((Player&)sprite).stopAllActions();
	((Player&)sprite).runAction(idle);
}

AnimationMng::AnimationMng()
{
}

AnimationMng::~AnimationMng()
{
}
