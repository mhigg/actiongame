#pragma once
#include <functional>
#include <array>
#include <cocos2d.h>
#include "DIR.h"

struct ActData;
enum class TIMING;

using ActFuncPtr = std::function<bool(cocos2d::Sprite&, ActData&)>;

enum class State
{
	move,		// 移動状態
	jump,		// ｼﾞｬﾝﾌﾟ状態
	jumping,	// ｼﾞｬﾝﾌﾟ中
	fall,		// 落下状態
	falling,	// 落下中
	idle,		// 停止状態
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
	std::array<cocos2d::Vec2, 2> col;	// 中心から当たり判定の座標までの長さ(向きによって上下2か所)
	DIR dir;							// 向き
	TIMING timing;						// 入力の状態
};

class ActionCtrl
{
public:
	ActionCtrl();
	~ActionCtrl();

	bool AddAction(const std::string actName, ActData& actData);
	void SetAction(const std::string actName);	// keycode, flipflag
	void Update(cocos2d::Sprite& sprite);

private:
	std::string _nowAction;					// 現在のｱｸｼｮﾝ名
	std::vector<ActFuncPtr> _actFuncList;	// Stateに応じたｱｸｼｮﾝ関数ﾎﾟｲﾝﾀを格納するﾘｽﾄ
	std::map<std::string, ActData> _actMap;	// ｱｸｼｮﾝﾃﾞｰﾀを格納する連想配列
};

