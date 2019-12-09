#pragma once
#include <functional>
#include <array>
#include <cocos2d.h>
#include "DIR.h"
#include "INPUT_ID.h"
#include "TIMING.h"

struct ActData;

// ｱｸｼｮﾝの関数ﾎﾟｲﾝﾀ型
using ActFuncPtr = std::function<bool(cocos2d::Sprite&, ActData&)>;

enum class STATE
{
	MOVE,		// 移動状態
	JUMP,		// ｼﾞｬﾝﾌﾟ状態
	JUMPING,	// ｼﾞｬﾝﾌﾟ中
	JUMPMOVE,	// ｼﾞｬﾝﾌﾟ中移動
	FALL,		// 落下状態
	FALLING,	// 落下中
	IDLE,		// 停止状態
	MAX
};

struct ActData
{
	STATE state;						// ｱｸｼｮﾝの状態名
	ActFuncPtr runAction;				// 実行するｱｸｼｮﾝの関数ﾎﾟｲﾝﾀ
	std::list<ActFuncPtr> act;			// 実行前にﾁｪｯｸする関数ﾎﾟｲﾝﾀﾘｽﾄ
	std::list<STATE> blackList;			// ﾌﾞﾗｯｸﾘｽﾄ(遷移不可能な状態ﾘｽﾄ)
	std::list<STATE> whiteList;			// ﾎﾜｲﾄﾘｽﾄ(遷移可能な状態ﾘｽﾄ)
	cocos2d::Point distance;			// ｱｸｼｮﾝ時の移動量
	std::array<cocos2d::Vec2, 2> col;	// 中心から当たり判定の座標までの長さ(上/右,下/左)
	DIR dir;							// 向き
	INPUT_ID inputID;					// 対応ｷｰ
	TIMING timing;						// 入力の状態
};

using ActVec = std::vector<ActFuncPtr>;
using ActMap = std::map<std::string, ActData>;

class ActionCtrl
	: public cocos2d::Ref
{
public:
	ActionCtrl();
	~ActionCtrl();

	// ｱｸｼｮﾝに必要なﾃﾞｰﾀをｱｸｼｮﾝ名ごとに登録する
	bool AddAction(const std::string actName, ActData& actData);
	// ｱｸｼｮﾝの更新処理
	void Update(cocos2d::Sprite& sprite);

private:
	ActVec _actFuncList;		// Stateに応じたｱｸｼｮﾝ関数ﾎﾟｲﾝﾀを格納するﾘｽﾄ
	ActMap _actMap;				// ｱｸｼｮﾝﾃﾞｰﾀを格納する連想配列
};