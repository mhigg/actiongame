#include "ActionCtrl.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include <input/OPRT_key.h>
#else
#include <input/OPRT_touch.h>
#endif
#include <unit/Player.h>
#include "moveLR.h"
#include "jumpUp.h"
#include "CheckKey.h"
#include "CheckList.h"
#include "CheckCollided.h"

ActionCtrl::ActionCtrl()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
	_inputState = std::make_unique<OPRT_key>();
#else
	_inputState.reset(new OPRT_touch());
#endif
	_actFuncList.emplace_back(idleNow());
	_actFuncList.emplace_back(moveLR());
	_actFuncList.emplace_back(jumpUp());
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
		_stateNameList.emplace_back(actName);
		return true;
	}

	return false;
}

void ActionCtrl::Update(cocos2d::Sprite& sprite)
{
	// ‚±‚±‚ÅÁª¯¸‚ð‚·‚é
	/**/

	for (auto name : _stateNameList)
	{
		if (_actMap[name].state == ((Player&)sprite).nowState())
		{
			_actMap[name].runAction(sprite, _actMap[name]);
			break;
		}
	}
}
