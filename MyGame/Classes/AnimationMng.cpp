#include "AnimationMng.h"
#include <unit/Player.h>

USING_NS_CC;

AnimationMng* AnimationMng::s_instance = nullptr;

void AnimationMng::AddAnimation(AnimData& animData)
{
	// loading plist file
	auto frameChache = SpriteFrameCache::getInstance();
	frameChache->addSpriteFramesWithFile("plists/" + animData.spType + "/" + animData.spName + "-" + animData.animName + ".plist");

	Animation* animation = Animation::create();
	for (int id = 1; id <= animData.frame; id++)
	{
		__String* str;
		if (animData.frame == 1)
		{
			str = __String::createWithFormat((animData.spName + "-" + animData.animName + ".png").c_str(), id);
		}
		else
		{
			str = __String::createWithFormat((animData.spName + "-" + animData.animName + "-%d.png").c_str(), id);
		}
		SpriteFrame* sprite = frameChache->getSpriteFrameByName(str->getCString());
		animation->addSpriteFrame(sprite);
	}

	animation->setDelayPerUnit(animData.delay);
	animation->setRestoreOriginalFrame(animData.restore);

	AnimationCache::getInstance()->addAnimation(animation, (animData.spName + "-" + animData.animName));
}

void AnimationMng::SetAnimation(cocos2d::Sprite& sprite, const std::string& animKey)
{
	auto cache = AnimationCache::getInstance()->getAnimation(animKey);
	auto idle = RepeatForever::create(Animate::create(cache));
	((Player&)sprite).runAction(idle);
}

AnimationMng::AnimationMng()
{
}

AnimationMng::~AnimationMng()
{
}
