#pragma once
#include <functional>
#include <cocos2d.h>
#include "DIR.h"
#include <input/OPRT_state.h>

struct ActData;

using ActFuncPtr = std::function<bool(cocos2d::Sprite&, ActData&)>;

enum class State
{
	idle,	// 停止状態
	move,	// 移動状態
	jump,	// ｼﾞｬﾝﾌﾟ状態
	max
};

struct ActData
{
	State state;						// ｱｸｼｮﾝの状態名
	ActFuncPtr runAction;				// 実行するｱｸｼｮﾝの関数ﾎﾟｲﾝﾀ
	std::list<ActFuncPtr> act;			// 実行前にﾁｪｯｸする関数ﾎﾟｲﾝﾀﾘｽﾄ
	std::list<State> blackList;			// ﾌﾞﾗｯｸﾘｽﾄ(遷移不可能な状態ﾘｽﾄ)
	std::list<State> whiteList;			// ﾎﾜｲﾄﾘｽﾄ(遷移可能な状態ﾘｽﾄ)
	cocos2d::Point distance;			// ｱｸｼｮﾝ時の移動量
	DIR dir;							// 向き
	TIMING timing;						// 
};

class ActionCtrl
{
public:
	ActionCtrl();
	~ActionCtrl();

	bool AddAction(const std::string actName, ActData& actData);
	void Update(void);

private:
	bool CheckHitObj(cocos2d::Sprite& sprite, ActData& actData);	// 足場や壁といったﾏｯﾌﾟとの当たり判定

	std::list<std::string> _stateNameList;	// ｱｸｼｮﾝ状態名を格納するﾘｽﾄ
	std::map<std::string, ActData> actMap;	// ｱｸｼｮﾝﾃﾞｰﾀを格納する連想配列

};

