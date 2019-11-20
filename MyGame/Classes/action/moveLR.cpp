#include "moveLR.h"
#include <unit/Player.h>

bool MoveLR::operator()(cocos2d::Sprite& sprite, ActData& actData)
{
	((Player&)sprite).setPosition(((Player&)sprite).getPosition() + actData.distance);
	return true;
}

bool Idling::operator()(cocos2d::Sprite& sprite, ActData& actData)
{
	return true;
}
