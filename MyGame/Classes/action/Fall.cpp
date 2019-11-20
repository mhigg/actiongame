#include "Fall.h"

bool FallDown::operator()(cocos2d::Sprite & sprite, ActData & actData)
{
	return false;
}

bool Falling::operator()(cocos2d::Sprite & sprite, ActData & actData)
{
	return false;
}
