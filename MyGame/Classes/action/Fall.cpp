#include "Fall.h"
#include <unit/Player.h>
#include <_DebugConOut.h>

bool FallDown::operator()(cocos2d::Sprite& sprite, ActData& actData)
{
	TRACE("fall\n");
	// —Ž‚¿Žn‚ß
	((Player&)sprite).nowState(STATE::FALLING);
	
	return true;
}

bool Falling::operator()(cocos2d::Sprite& sprite, ActData& actData)
{
	TRACE("falling\n");
	// ‰º‚Ì“–‚½‚è”»’è‚ª‚ ‚é‚Ü‚Å—Ž‚¿‚é‚¾‚¯

	((Player&)sprite).setPosition(((Player&)sprite).getPosition() + actData.distance);

	return true;
}
