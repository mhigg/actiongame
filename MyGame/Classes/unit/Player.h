#pragma once
#include <cocos2d.h>
#include <action/ActionCtrl.h>
#include <input/OPRT_state.h>

//USING_NS_CC;

class Player;

class Player :
	public Sprite
{
public:
	static Player* createPlayer();

	Player();
	~Player();

	void update(float delta);

	const State nowState(void) const;
	
	// implement the "static create()" method manually
	CREATE_FUNC(Player);

private:
	void (Player::*updater)(void);

	void InitAction(void);

	void UpdateIdle(void);	// 停止状態
	void UpdateMove(void);	// 移動状態
	void UpdateJump(void);	// ｼﾞｬﾝﾌﾟ状態

	void CheckGID(void);	// 現在の座標のGIDの検索

	State _nowState;			// 現在のｱｸｼｮﾝ状態
	bool gravity;			// true:重力あり false:重力なし
	bool jumpFlag;			// true:ｼﾞｬﾝﾌﾟ中 false:非ｼﾞｬﾝﾌﾟ
	Action* jumpAct = nullptr;
	std::vector<bool> collision;

	float speed;			// 移動速度
	std::array<Vec2, static_cast<int>(DIR::MAX)> moveSpeed;

	uniqueOPRT _inputState;		// 入力情報取得変数
	ActionCtrl* _actCtrl;		// ｱｸｼｮﾝ制御用ｸﾗｽ変数
};

