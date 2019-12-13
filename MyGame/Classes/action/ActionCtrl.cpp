#include "ActionCtrl.h"
#include <unit/Player.h>
#include "ActionInclude.h"
#include "CheckInclude.h"
//#include <_DebugConOut.h>

ActionCtrl::ActionCtrl()
{
	// STATEに応じたｱｸｼｮﾝの関数ﾎﾟｲﾝﾀをﾘｽﾄに登録
	_actFuncList.emplace_back(MoveLR());
	_actFuncList.emplace_back(JumpUp());
	_actFuncList.emplace_back(Jumping());
	_actFuncList.emplace_back(FallDown());
	_actFuncList.emplace_back(Falling());
	_actFuncList.emplace_back(Idling());
}

ActionCtrl::~ActionCtrl()
{
}

bool ActionCtrl::AddAction(const std::string actName, ActData& actData)
{
	if (_actMap.find(actName) == _actMap.end())
	{
		_actMap.emplace(actName, std::move(actData));
		_actMap[actName].act.emplace_back(CheckKey());
		_actMap[actName].act.emplace_back(CheckList());
		_actMap[actName].act.emplace_back(CheckHitObj());
		_actMap[actName].runAction = _actFuncList[static_cast<int>(actData.state)];
		return true;
	}

	return false;
}

void ActionCtrl::Update(cocos2d::Sprite& sprite)
{
	// ﾁｪｯｸ関数
	auto checkAct = [&sprite](ActData& data) {
		for (auto check : data.act)
		{
			if (!check(sprite, data))
			{
				return false;
			}
		}
		return true;
	};
	
	bool changeAct = false;
	for (auto data : _actMap)
	{
		if (checkAct(data.second))
		{
			data.second.runAction(sprite, data.second);

			auto state = ((Player&)sprite).nowState();
			if (state == STATE::MOVE)
			{
				SetDir()(sprite, data.second);	// ←向きの切り替えをしてもよいｱｸｼｮﾝのときのみ呼ぶようにする
			}

			if (!(state == STATE::JUMP || state == STATE::JUMPING
			 ||   state == STATE::FALL || state == STATE::FALLING))
			{
				//TRACE("changeState\n");
				((Player&)sprite).nowState(data.second.state);
			}
			changeAct = true;
		}
	}

	if (!changeAct)
	{
		_actMap["Idle"].runAction(sprite, _actMap["Idle"]);
	}
}
