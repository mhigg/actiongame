#include "Enemy.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include <input/OPRT_key.h>
#else
#include <input/OPRT_touch.h>
#endif
#include "DIR.h"
#include "AnimationMng.h"

USING_NS_CC;

Enemy* Enemy::createEnemy()
{
	return Enemy::create();
}

Enemy::Enemy()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
	_inputState = std::make_unique<OPRT_key>();
#else
	_inputState.reset(new OPRT_touch());
#endif
	_inputState->Init(this);

	InitAction();
	_nowState = STATE::IDLE;

	InitAnimation();
	lpAnimMng.SetAnimation(*this, "crab-idle");

	this->scheduleUpdate();
}


Enemy::~Enemy()
{
}

void Enemy::update(float delta)
{
	_inputState->Update();
}

void Enemy::InitAction(void)
{
	{	/* ‘Ò‹@ */
		AnimData animData;
		animData.spType = "enemies";
		animData.spName = "crab";
		animData.animName = "idle";
		animData.frame = 4;
		animData.delay = 0.05f;
		animData.restore = true;

		lpAnimMng.AddAnimation(animData);
	}
}

void Enemy::InitAnimation(void)
{
}
