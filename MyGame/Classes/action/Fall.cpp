#include "Fall.h"
#include <unit/Player.h>
//#include <_DebugConOut.h>

bool FallDown::operator()(cocos2d::Sprite& sprite, ActData& actData)
{
	//TRACE("fall\n");
	// 落ち始め
	((Player&)sprite).nowState(STATE::FALLING);
	
	return true;
}

bool Falling::operator()(cocos2d::Sprite& sprite, ActData& actData)
{
	//TRACE("falling\n");
	// 下の当たり判定があるまで落ちるだけ

	((Player&)sprite).setPosition(((Player&)sprite).getPosition() + actData.distance);

	return true;
}
