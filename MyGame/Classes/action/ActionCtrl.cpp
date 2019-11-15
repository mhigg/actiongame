#include "ActionCtrl.h"
#include "moveLR.h"
#include "CheckList.h"
#include "CheckCollided.h"

ActionCtrl::ActionCtrl()
{
	_stateNameList = {
		"停止",
		"走る",
		"ジャンプ"
	};
}


ActionCtrl::~ActionCtrl()
{
}

bool ActionCtrl::AddAction(const std::string actName, ActData& actData)
{
	actMap.try_emplace(actName, std::move(actData));
	actMap[actName].act.emplace_back(CheckList());
//	actMap[actName].act.emplace_back(CheckHitObj());
	actMap[actName].runAction = moveLR();
	return false;
}

void ActionCtrl::Update(void)
{
	// ﾁｪｯｸして実行
}

bool ActionCtrl::CheckHitObj(cocos2d::Sprite& sprite, ActData& actData)
{
	return false;
}
