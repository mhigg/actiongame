#include "Player.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include <input/OPRT_key.h>
#else
#include <input/OPRT_touch.h>
#endif
#include "DIR.h"
#include "AnimationMng.h"

USING_NS_CC;

Player* Player::createPlayer()
{
	return Player::create();
}

Player::Player()
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
	lpAnimMng.SetAnimation(*this, "player-idle");

	_dir = DIR::CENTER;

	this->scheduleUpdate();
}

Player::~Player()
{
	//delete _actCtrl;
}

void Player::update(float delta)
{
	_inputState->Update();
	_actCtrl->Update(*this);
}

const STATE Player::nowState(void) const
{
	return _nowState;
}

void Player::nowState(const STATE state)
{
	_nowState = state;
}

const DIR Player::dir(void) const
{
	return _dir;
}

void Player::dir(const DIR direction)
{
	_dir = direction;
}

const uniqueOPRT& Player::inputState(void)
{
	return _inputState;
}

void Player::InitAction(void)
{
	_actCtrl = new ActionCtrl();
	
	{	/* ���ړ��̓o�^ */
		ActData actData;
		actData.state = STATE::MOVE;
		actData.whiteList.emplace_back(STATE::MOVE);
		actData.whiteList.emplace_back(STATE::JUMP);
		actData.whiteList.emplace_back(STATE::FALL);
		actData.dir = DIR::LEFT;
		actData.col[0] = Vec2{ -30, 50 };
		actData.col[1] = Vec2{ -30,-50 };
		actData.distance = Point(-4.0f, 0.0f);
		actData.inputID = INPUT_ID::LEFT;
		actData.timing = TIMING::ON;

		_actCtrl->AddAction("���ړ�", actData);
	}

	{	/* �E�ړ��̓o�^ */
		ActData actData;
		actData.state = STATE::MOVE;
		actData.whiteList.emplace_back(STATE::MOVE);
		actData.whiteList.emplace_back(STATE::JUMP);
		actData.whiteList.emplace_back(STATE::FALL);
		actData.dir = DIR::RIGHT;
		actData.col[0] = Vec2{ 30, 50 };
		actData.col[1] = Vec2{ 30,-50 };
		actData.distance = Point(4.0f, 0.0f);
		actData.inputID = INPUT_ID::RIGHT;
		actData.timing = TIMING::ON;

		_actCtrl->AddAction("�E�ړ�", actData);
	}
	
	{	/* ��ړ��̓o�^ */
		ActData actData;
		actData.state = STATE::MOVE;
		actData.whiteList.emplace_back(STATE::MOVE);
		actData.whiteList.emplace_back(STATE::JUMP);
		actData.whiteList.emplace_back(STATE::FALL);
		actData.dir = DIR::RIGHT;
		actData.col[0] = Vec2{  20, 60 };
		actData.col[1] = Vec2{ -20, 60 };
		actData.distance = Point(0.0f, 4.0f);
		actData.inputID = INPUT_ID::UP;
		actData.timing = TIMING::ON;

		_actCtrl->AddAction("��ړ�", actData);
	}

	{	/* ���ړ��̓o�^ */
		ActData actData;
		actData.state = STATE::MOVE;
		actData.whiteList.emplace_back(STATE::MOVE);
		actData.whiteList.emplace_back(STATE::JUMP);
		actData.whiteList.emplace_back(STATE::FALL);
		actData.dir = DIR::RIGHT;
		actData.col[0] = Vec2{  20, -80 };
		actData.col[1] = Vec2{ -20, -80 };
		actData.distance = Point(0.0f, -4.0f);
		actData.inputID = INPUT_ID::DOWN;
		actData.timing = TIMING::ON;

		_actCtrl->AddAction("���ړ�", actData);
	}

	//{	/* �ެ��ߊJ�n�o�^ */
	//	ActData actData;
	//	actData.state = STATE::JUMP;
	//	actData.whiteList.emplace_back(STATE::MOVE);
	//	actData.blackList.emplace_back(STATE::JUMP);
	//	actData.dir = _dir;
	//	actData.col[0] = Vec2{  20, 50 };
	//	actData.col[1] = Vec2{ -20, 50 };
	//	actData.distance = Point(0.0f, 2.0f);
	//	actData.inputID = INPUT_ID::UP;
	//	actData.timing = TIMING::ON_MOM;

	//	_actCtrl->AddAction("�W�����v�J�n", actData);
	//}

	//{	/* �ެ��ߒ��o�^ */
	//	ActData actData;
	//	actData.state = STATE::JUMP;
	//	actData.whiteList.emplace_back(STATE::MOVE);
	//	actData.blackList.emplace_back(STATE::JUMP);
	//	actData.dir = _dir;
	//	actData.col[0] = Vec2{  20, 50 };
	//	actData.col[1] = Vec2{ -20, 50 };
	//	actData.distance = Point(0.0f, 2.0f);
	//	actData.inputID = INPUT_ID::UP;
	//	actData.timing = TIMING::ON_MOM;

	//	_actCtrl->AddAction("�W�����v��", actData);
	//}

	//{	/* �����J�n�o�^ */
	//	ActData actData;
	//	actData.state = STATE::FALL;
	//	actData.whiteList.emplace_back(STATE::MOVE);
	//	actData.blackList.emplace_back(STATE::JUMP);
	//	actData.blackList.emplace_back(STATE::FALL);
	//	actData.dir = _dir;
	//	actData.col[0] = Vec2{ 20, 50 };
	//	actData.col[1] = Vec2{ -20, 50 };
	//	actData.distance = Point(0.0f, -2.0f);
	//	actData.inputID = INPUT_ID::DOWN;
	//	actData.timing = TIMING::ON_MOM;

	//	_actCtrl->AddAction("�����J�n", actData);
	//}

	//{	/* �������o�^ */
	//	ActData actData;
	//	actData.state = STATE::FALLING;
	//	actData.whiteList.emplace_back(STATE::MOVE);
	//	actData.blackList.emplace_back(STATE::JUMP);
	//	actData.blackList.emplace_back(STATE::FALL);
	//	actData.dir = _dir;
	//	actData.col[0] = Vec2{ 20, 50 };
	//	actData.col[1] = Vec2{ -20, 50 };
	//	actData.distance = Point(0.0f, -2.0f);
	//	actData.inputID = INPUT_ID::DOWN;
	//	actData.timing = TIMING::ON_MOM;

	//	_actCtrl->AddAction("������", actData);
	//}

}

void Player::InitAnimation(void)
{
	{	/* �ҋ@ */
		AnimData animData;
		animData.spType = "player";
		animData.spName = "player";
		animData.animName = "idle";
		animData.frame = 4;
		animData.delay = 0.2f;
		animData.restore = true;

		lpAnimMng.AddAnimation(animData);
	}

	{	/* �ړ� */
		AnimData animData;
		animData.spType = "player";
		animData.spName = "player";
		animData.animName = "run";
		animData.frame = 10;
		animData.delay = 0.05f;
		animData.restore = true;

		lpAnimMng.AddAnimation(animData);
	}

	{	/* �W�����v */
		AnimData animData;
		animData.spType = "player";
		animData.spName = "player";
		animData.animName = "jump";
		animData.frame = 6;
		animData.delay = 0.05f;
		animData.restore = true;

		lpAnimMng.AddAnimation(animData);
	}
}
