#include "SetDir.h"
#include <unit/Player.h>

bool SetDir::operator()(cocos2d::Sprite& sprite, ActData& actData)
{
	((Player&)sprite).dir(actData.dir);
	return true;
}