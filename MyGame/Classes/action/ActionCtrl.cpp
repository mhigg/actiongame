#include "ActionCtrl.h"
#include <unit/Player.h>
#include "moveLR.h"
#include "Jump.h"
#include "SetDir.h"
#include <check/CheckKey.h>
#include <check/CheckList.h>
#include <check/CheckCollided.h>

ActionCtrl::ActionCtrl()
{
	_actFuncList.emplace_back(moveLR());
	_actFuncList.emplace_back(jumpUp());
	//_actFuncList.emplace_back(jumpNow());
	//_actFuncList.emplace_back(fallDown());
	//_actFuncList.emplace_back(fallNow());
	//_actFuncList.emplace_back(idleNow());
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
		//_actMap[actName].act.emplace_back(CheckList());
		//_actMap[actName].act.emplace_back(CheckHitObj());
		_actMap[actName].runAction = _actFuncList[static_cast<int>(actData.state)];
		return true;
	}

	return false;
}

void ActionCtrl::SetAction(const std::string actName)
{
	_nowAction = actName;
}

void ActionCtrl::Update(cocos2d::Sprite& sprite)
{
	SetDir()(sprite, _actMap[_nowAction]);

	if (_nowAction == "‘Ò‹@")
	{
		return;
	}

	// ‚±‚±‚ÅÁª¯¸‚ð‚·‚é
	/**/
	for (auto check : _actMap[_nowAction].act)
	{
		if (check(sprite, _actMap[_nowAction]))
		{
			_actMap[_nowAction].runAction(sprite, _actMap[_nowAction]);
		}
	}
}
