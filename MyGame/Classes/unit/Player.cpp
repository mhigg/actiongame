#include "Player.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include <input/OPRT_key.h>
#else
#include <input/OPRT_touch.h>
#endif
#include <action/moveLR.h>
#include <action/jumpUp.h>
#include "DIR.h"
#include "CreateAnim.h"
#include <_DebugConOut.h>

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

	speed = 6.0f;
	gravity = true;
	jumpFlag = false;

	moveSpeed = {
		Vec2{-speed,  0.0f},
		Vec2{ speed,  0.0f},
		Vec2{ 0.0f,  speed},
		Vec2{ 0.0f, -speed},
		Vec2{ 0.0f,   0.0f}
	};

	// creating animation

	CreateAnim()("player", "player", "idle", 4);
	CreateAnim()("player", "player", "run", 10);
	CreateAnim()("player", "player", "jump", 6);

	auto cache = AnimationCache::getInstance()->getAnimation("player-idle");

	// set first action
	FiniteTimeAction* idle = RepeatForever::create(Animate::create(cache));

	this->runAction(idle);

	updater = &Player::UpdateIdle;

	InitAction();

	_inputState->Init(this);

	this->scheduleUpdate();
}

Player::~Player()
{
}

void Player::update(float delta)
{
//	State oldState = nowState;
	_inputState->Update();
	auto pos = this->getPosition();
	Vec2 size = { 50,120 };

	_actCtrl->Update();

	if (_inputState->GetInputAry()[0][nowTrg] & ~_inputState->GetInputAry()[0][oldTrg])
	{
		auto flip = FlipX::create(true);
		this->runAction(flip);
		// ﾘｽﾄﾁｪｯｸを挟んでrunAction
		//moveLR()(*this);
	}
	
	//if (pos.x - size.x / 2 < 0 || 1024 < pos.x + size.x / 2
	// || pos.y - size.y / 2 < 0 ||  576 < pos.y + size.y / 2)
	//{
	//	this->setPosition(pos + moveSpeed[static_cast<int>(dir)]);
	//}
	//else
	//{
	//	if (gravity)
	//	{
	//		this->setPosition(pos + moveSpeed[static_cast<int>(DIR::DOWN)]);
	//	}

	//	CheckGID();
	//}
	
}

const State Player::nowState(void) const
{
	return _nowState;
}


void Player::InitAction(void)
{
	ActData actData;
	actData.state = State::move;
	actData.whiteList.emplace_back(State::move);
	actData.whiteList.emplace_back(State::jump);
	actData.timing = TIMING::ON;

	_actCtrl->AddAction("走る", actData);
}

// 停止状態での処理
void Player::UpdateIdle(void)
{
	// 向き変更
	// 移動処理←関数ポインタ←ホワイトリストで管理

	for (auto dirID = begin(DIR()); dirID <= DIR::RIGHT; ++dirID)
	{
		if (_inputState->GetInputAry()[static_cast<int>(dirID)][nowTrg] & ~(_inputState->GetInputAry()[static_cast<int>(dirID)][oldTrg]))
		{
			this->stopAllActions();
			auto flip = FlipX::create((dirID == DIR::LEFT ? true : false));
			this->runAction(flip);
			//auto anim = AnimationCache::getInstance()->getAnimation("player-run");
			//this->runAction(RepeatForever::create(Animate::create(anim)));
			return;
		}
	}

	//※ｼﾞｬﾝﾌﾟ処理のﾓｼﾞｭｰﾙ化？

	if (_inputState->GetInputAry()[static_cast<int>(DIR::UP)][nowTrg] & ~(_inputState->GetInputAry()[static_cast<int>(DIR::UP)][oldTrg]))
	{
		jumpFlag = true;
		this->stopAllActions();
		//dir = DIR::UP;
		//auto move = MoveBy::create(0.0f, moveSpeed[static_cast<int>(DIR::UP)]*2);
		//this->runAction(move);
		auto anim = AnimationCache::getInstance()->getAnimation("player-jump");
		auto animation = Repeat::create(Animate::create(anim), 1);
		auto jump = JumpBy::create(1.0f, Vec2::ZERO, 180.0f, 1);
		jumpAct = this->runAction(Spawn::create(jump, animation, nullptr));
		CC_SAFE_RETAIN(jumpAct);
		return;
	}

	//if (_inputState->GetInputAry()[static_cast<int>(DIR::DOWN)][nowTrg])
	//{
	//	this->stopAllActions();
	//	dir = DIR::DOWN;
	//	auto move = MoveBy::create(0.0f, moveSpeed[static_cast<int>(DIR::DOWN)]);
	//	this->runAction(move);
	//	return;
	//}

}

// 移動状態での処理
void Player::UpdateMove(void)
{
	if (_inputState->GetInputAry()[static_cast<int>(DIR::LEFT)][nowTrg])
	{
		auto flip = FlipX::create(true);
		this->runAction(flip);
		this->runAction(MoveBy::create(0.0f, moveSpeed[static_cast<int>(DIR::LEFT)]));
	}
	else if (_inputState->GetInputAry()[static_cast<int>(DIR::RIGHT)][nowTrg])
	{
		auto flip = FlipX::create(false);
		this->runAction(flip);
		this->runAction(MoveBy::create(0.0f, moveSpeed[static_cast<int>(DIR::RIGHT)]));
	}
	else
	{
		this->stopAllActions();
		this->runAction(RepeatForever::create(Animate::create(AnimationCache::getInstance()->getAnimation("player-idle"))));
	}

	if (_inputState->GetInputAry()[static_cast<int>(DIR::UP)][nowTrg] & ~(_inputState->GetInputAry()[static_cast<int>(DIR::UP)][oldTrg]))
	{
		jumpFlag = true;
		this->stopAllActions();
		auto anim = AnimationCache::getInstance()->getAnimation("player-jump");
		auto animation = Repeat::create(Animate::create(anim), 1);
		CC_SAFE_RETAIN(jumpAct);
		return;
	}

}

// ｼﾞｬﾝﾌﾟ中の処理
void Player::UpdateJump(void)
{
	if (jumpAct->isDone())
	{
		jumpFlag = false;
	}

	for (auto dirID = begin(DIR()); dirID <= DIR::RIGHT; ++dirID)
	{
		if (_inputState->GetInputAry()[static_cast<int>(dirID)][nowTrg])
		{
			auto flip = FlipX::create((dirID == DIR::LEFT ? true : false));
			this->runAction(flip);
		}
	}


	// return idle after finished jumping
	if (jumpAct != nullptr)
	{
		if (!jumpFlag)
		{
			this->stopAllActions();
			if (_inputState->GetInputAry()[static_cast<int>(DIR::RIGHT)][nowTrg])
			{
				auto anim = AnimationCache::getInstance()->getAnimation("player-run");
				FiniteTimeAction* run = RepeatForever::create(Animate::create(anim));
				this->runAction(run);
				auto flip = FlipX::create(false);
				this->runAction(flip);
				auto move = MoveBy::create(1.0f, moveSpeed[static_cast<int>(DIR::RIGHT)]);
				this->runAction(move);
			}
			else if (_inputState->GetInputAry()[static_cast<int>(DIR::LEFT)][nowTrg])
			{
				auto anim = AnimationCache::getInstance()->getAnimation("player-run");
				FiniteTimeAction* run = RepeatForever::create(Animate::create(anim));
				this->runAction(run);
				auto flip = FlipX::create(true);
				this->runAction(flip);
				auto move = MoveBy::create(1.0f, moveSpeed[static_cast<int>(DIR::LEFT)]);
				this->runAction(move);
			}
			else
			{
				auto anim = AnimationCache::getInstance()->getAnimation("player-idle");
				FiniteTimeAction* idle = RepeatForever::create(Animate::create(anim));
				this->runAction(idle);
			}
			CC_SAFE_RELEASE(jumpAct);
		}
	}
	else
	{
		CC_ASSERT("jumpAct is nullptr");
		this->stopAllActions();
		auto anim = AnimationCache::getInstance()->getAnimation("player-idle");
		FiniteTimeAction* idle = RepeatForever::create(Animate::create(anim));
		this->runAction(idle);
		CC_SAFE_RELEASE(jumpAct);

	}
}

void Player::CheckGID(void)
{
	// get mapChipData
	auto director = Director::getInstance();
	auto map = (TMXTiledMap*)director->getRunningScene()->getChildByName("groundLayer")->getChildByName("mapData");
	auto col = map->getLayer("ground");
	auto mapSize = map->getMapSize();

	auto tmpPos = this->getPosition();
	auto size = Vec2{ 50,120 };

	auto rightpos		= Vec2((tmpPos.x + size.x / 2) / 48, tmpPos.y / 48);
	auto uprightpos		= Vec2((tmpPos.x + size.x / 2) / 48, mapSize.height - (tmpPos.y + size.y / 2) / 48);
	auto downrightpos	= Vec2((tmpPos.x + size.x / 2) / 48, mapSize.height - (tmpPos.y - size.y / 2) / 48);

	if (col->getTileGIDAt(rightpos)		 != 0
	 || col->getTileGIDAt(uprightpos)	 != 0
	 || col->getTileGIDAt(downrightpos)	 != 0)
	{
		this->setPosition(Vec2(tmpPos.x - speed, tmpPos.y));
	}

	auto leftpos		= Vec2((tmpPos.x - size.x / 2) / 48, tmpPos.y / 48);
	auto upleftpos		= Vec2((tmpPos.x - size.x / 2) / 48, mapSize.height - (tmpPos.y + size.y / 2) / 48);
	auto downleftpos	= Vec2((tmpPos.x - size.x / 2) / 48, mapSize.height - (tmpPos.y - size.y / 2) / 48);

	if (col->getTileGIDAt(leftpos)		!= 0
	 || col->getTileGIDAt(upleftpos)	!= 0
	 || col->getTileGIDAt(downleftpos)	!= 0)
	{
		this->setPosition(Vec2(tmpPos.x + speed, tmpPos.y));
	}

	auto legpos = Vec2(tmpPos.x / 48, (mapSize.height - (tmpPos.y - size.y / 2) / 48));

	if ((col->getTileGIDAt(downleftpos)  != 0 && col->getTileGIDAt(legpos) != 0)
	 || (col->getTileGIDAt(downrightpos) != 0 && col->getTileGIDAt(legpos) != 0))
	{
		this->setPosition(Vec2(tmpPos.x, tmpPos.y + (tmpPos.y - ((mapSize.height - legpos.y) + 1) * 48)));
		gravity = false;
	}

	auto headpos = Vec2(tmpPos.x / 48, (mapSize.height - (tmpPos.y + size.y / 2) / 48));

	if (col->getTileGIDAt(headpos) != 0)
	{
		jumpFlag = false;
		this->setPosition(Vec2(tmpPos.x, tmpPos.y - speed));
	}
}
