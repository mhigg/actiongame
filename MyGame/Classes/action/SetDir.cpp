#include "SetDir.h"
#include <unit/Player.h>

bool SetDir::operator()(cocos2d::Sprite& sprite, ActData& actData)
{
	((Player&)sprite).dir(actData.dir);
	if (actData.dir == DIR::LEFT)
	{
		((Player&)sprite).runAction(cocos2d::FlipX::create(true));
	}
	if (actData.dir == DIR::RIGHT)
	{
		((Player&)sprite).runAction(cocos2d::FlipX::create(false));
	}
	return true;
}
