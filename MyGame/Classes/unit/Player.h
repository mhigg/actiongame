#pragma once
#include "cocos2d.h"
#include <input/OPRT_state.h>

//USING_NS_CC;

enum class STATE
{
	IDLE,	// 停止状態
	MOVE,	// 移動状態
	JUMP,	// ｼﾞｬﾝﾌﾟ状態
	MAX
};

class Player;

class Player :
	public Sprite
{
public:
	static Player* createPlayer();

	Player();
	~Player();

	void update(float delta);

	// implement the "static create()" method manually
	CREATE_FUNC(Player);

private:
	void (Player::*updater)(void);

	void UpdateIdle(void);	// 停止状態
	void UpdateMove(void);	// 移動状態
	void UpdateJump(void);	// ｼﾞｬﾝﾌﾟ状態



	void CheckGID(void);	// 現在の座標のGIDの検索

	DIR dir;				// 向き
	STATE nowState;			// 現在の状態
	bool gravity;			// true:重力あり false:重力なし
	bool jumpFlag;			// true:ｼﾞｬﾝﾌﾟ中 false:非ｼﾞｬﾝﾌﾟ
	Action* jumpAct = nullptr;
	std::vector<bool> collision;

	float speed;			// 移動速度
	std::array<Vec2, static_cast<int>(DIR::MAX)> moveSpeed;

	uniqueOPRT input;		// 入力情報取得変数
};

