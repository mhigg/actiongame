#include "Jump.h"
#include <unit/Player.h>
#include <_DebugConOut.h>

USING_NS_CC;

bool JumpUp::operator()(cocos2d::Sprite& sprite, ActData& actData)
{
	TRACE("jump\n");
	((Player&)sprite).jumpSpeed(Vec2(0.0f, 10.0f));
	((Player&)sprite).nowState(STATE::JUMPING);
	return true;
}

bool Jumping::operator()(cocos2d::Sprite & sprite, ActData & actData)
{
	TRACE("jumping\n");
	auto jumpSpeed = ((Player&)sprite).jumpSpeed();
	((Player&)sprite).setPosition(((Player&)sprite).getPosition() + jumpSpeed);
	((Player&)sprite).jumpSpeed({ jumpSpeed.x, jumpSpeed.y - 0.5f });
	if (jumpSpeed.y < 0)
	{
		// I‚í‚Á‚½‚çfall‚ÉˆÚs
		((Player&)sprite).nowState(STATE::FALLING);
	}

	return true;
}
