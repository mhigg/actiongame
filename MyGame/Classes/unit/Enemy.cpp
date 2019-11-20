#include "Enemy.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include <input/OPRT_key.h>
#else
#include <input/OPRT_touch.h>
#endif
#include "DIR.h"
#include "CreateAnim.h"
#include <_DebugConOut.h>

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

	CreateAnim()("enemies", "crab", "idle", 4);

	auto cache = AnimationCache::getInstance()->getAnimation("crab-idle");

	// set first action
	FiniteTimeAction* idle = RepeatForever::create(Animate::create(cache));

	this->runAction(idle);

	_inputState->Init(this);

	this->scheduleUpdate();
}


Enemy::~Enemy()
{
}

void Enemy::update(float delta)
{
	_inputState->Update();
}
