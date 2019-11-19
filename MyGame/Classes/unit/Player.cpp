#include "Player.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include <input/OPRT_key.h>
#else
#include <input/OPRT_touch.h>
#endif
#include <action/moveLR.h>
#include <action/Jump.h>
#include "DIR.h"
#include "CreateAnim.h"
#include <_DebugConOut.h>

USING_NS_CC;

Player* Player::createPlayer()
{
	return Player::create();
}

Player::Player() : _actCtrl(new ActionCtrl())
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
	_inputState = std::make_unique<OPRT_key>();
#else
	_inputState.reset(new OPRT_touch());
#endif
	// player status initialize

	// creating animation

	CreateAnim()("player", "player", "idle", 4);
	CreateAnim()("player", "player", "run", 10);
	CreateAnim()("player", "player", "jump", 6);

	InitAction();
	_inputState->Init(this);

	auto cache = AnimationCache::getInstance()->getAnimation("player-idle");

	// set first action
	FiniteTimeAction* idle = RepeatForever::create(Animate::create(cache));

	this->runAction(idle);

	_dir = DIR::CENTER;
	_actCtrl->SetAction("‘Ò‹@");
	_nowState = State::idle;

	this->scheduleUpdate();
}

Player::~Player()
{
}

void Player::update(float delta)
{
	_inputState->Update();
	_actCtrl->Update(*this);

	if (_inputState->GetInputAry()[0][nowTrg] & ~_inputState->GetInputAry()[0][oldTrg])
	{
		_actCtrl->SetAction("¶ˆÚ“®");
		_nowState = State::move;
		auto flip = FlipX::create(true);
		this->runAction(flip);
	}
	if (_inputState->GetInputAry()[1][nowTrg] & ~_inputState->GetInputAry()[1][oldTrg])
	{
		_actCtrl->SetAction("‰EˆÚ“®");
		_nowState = State::move;
		auto flip = FlipX::create(false);
		this->runAction(flip);
	}
}

const State Player::nowState(void) const
{
	return _nowState;
}

void Player::nowState(const State state)
{
	_nowState = state;
}

void Player::dir(const DIR direction)
{
	_dir = direction;
}

const uniqueOPRT& Player::inputState(void)
{
	return _inputState;
}

const DIR Player::dir(void) const
{
	return _dir;
}

void Player::InitAction(void)
{
	// ¶ˆÚ“®‚Ì“o˜^
	{
		ActData actData;
		actData.state = State::move;
		actData.whiteList.emplace_back(State::move);
		actData.whiteList.emplace_back(State::jump);
		actData.dir = DIR::LEFT;
		actData.col[0] = Vec2{ -30, 50 };
		actData.col[1] = Vec2{ -30,-50 };
		actData.distance = Point(-2.0f, 0.0f);
		actData.timing = TIMING::ON;

		_actCtrl->AddAction("¶ˆÚ“®", actData);
	}
	// ‰EˆÚ“®‚Ì“o˜^
	{
		ActData actData;
		actData.state = State::move;
		actData.whiteList.emplace_back(State::move);
		actData.whiteList.emplace_back(State::jump);
		actData.dir = DIR::RIGHT;
		actData.col[0] = Vec2{ 30, 50 };
		actData.col[1] = Vec2{ 30,-50 };
		actData.distance = Point(2.0f, 0.0f);
		actData.timing = TIMING::ON;

		_actCtrl->AddAction("‰EˆÚ“®", actData);
	}
	// ¼Þ¬ÝÌß“o˜^
	{
		ActData actData;
		actData.state = State::jump;
		actData.whiteList.emplace_back(State::move);
		actData.blackList.emplace_back(State::jump);
		actData.dir = DIR::UP;
		actData.col[0] = Vec2{  30, 50 };
		actData.col[1] = Vec2{ -30, 50 };
		actData.distance = Point(0.0f, 2.0f);
		actData.timing = TIMING::ON_MOM;

		_actCtrl->AddAction("ƒWƒƒƒ“ƒv", actData);
	}
}
