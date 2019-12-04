#include "Fall.h"
#include <unit/Player.h>
#include <_DebugConOut.h>

bool FallDown::operator()(cocos2d::Sprite& sprite, ActData& actData)
{
	TRACE("fall\n");
	// �����n��
	((Player&)sprite).nowState(STATE::FALLING);
	
	return true;
}

bool Falling::operator()(cocos2d::Sprite& sprite, ActData& actData)
{
	TRACE("falling\n");
	// ���̓����蔻�肪����܂ŗ����邾��

	((Player&)sprite).setPosition(((Player&)sprite).getPosition() + actData.distance);

	return true;
}
