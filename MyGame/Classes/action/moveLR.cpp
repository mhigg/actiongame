#include "moveLR.h"
#include <unit/Player.h>

bool moveLR::operator()(cocos2d::Sprite& sprite, ActData& actData)
{
	((Player&)sprite).setPosition(((Player&)sprite).getPosition() + actData.distance);
	return true;
}

bool idleNow::operator()(cocos2d::Sprite & sprite, ActData & actData)
{
	return true;
}
