#include "Jump.h"
#include <unit/Player.h>
//#include <_DebugConOut.h>

bool JumpUp::operator()(cocos2d::Sprite& sprite, ActData& actData)
{
	//TRACE("jump\n");
	((Player&)sprite).nowState(STATE::JUMPING);
	return true;
}

bool Jumping::operator()(cocos2d::Sprite & sprite, ActData & actData)
{
	//TRACE("jumping\n");
	((Player&)sprite).setPosition(((Player&)sprite).getPosition() + ((Player&)sprite).jumpSpeed());
	return true;
}
