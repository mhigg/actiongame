#include "moveLR.h"
#include <unit/Player.h>
#include <_DebugConOut.h>

bool MoveLR::operator()(cocos2d::Sprite& sprite, ActData& actData)
{
	TRACE("move\n");
	((Player&)sprite).nowState(STATE::MOVE);
	((Player&)sprite).setPosition(((Player&)sprite).getPosition() + actData.distance);
	return true;
}

bool JumpLR::operator()(cocos2d::Sprite& sprite, ActData& actData)
{
	TRACE("jumpMove\n");
	((Player&)sprite).nowState(STATE::JUMPMOVE);
	((Player&)sprite).setPosition(((Player&)sprite).getPosition() + actData.distance);
	return true;
}

bool Idling::operator()(cocos2d::Sprite& sprite, ActData& actData)
{
	TRACE("idle\n");
	((Player&)sprite).nowState(STATE::IDLE);
	return true;
}
