#pragma once
#include <cocos2d.h>
#include <action/ActionCtrl.h>
#include <input/OPRT_state.h>

class Player;

class Player :
	public cocos2d::Sprite
{
public:
	static Player* createPlayer();

	Player();
	~Player();

	void update(float delta);			// 更新処理
	
	const State nowState(void) const;	// 現在のｱｸｼｮﾝ状態を取得する
	void nowState(const State state);	// 現在のｱｸｼｮﾝ状態をｾｯﾄする
	const DIR dir(void) const;			// 向きを取得する
	void dir(const DIR direction);		// 向きをｾｯﾄする
	const uniqueOPRT& inputState(void);	// 入力情報を取得する

	// implement the "static create()" method manually
	CREATE_FUNC(Player);

private:
	void InitAction(void);	// ｱｸｼｮﾝの初期登録

	std::string _nowAction;	// ｱｸｼｮﾝ状態名
	State _nowState;		// 現在のｱｸｼｮﾝ状態
	DIR _dir;				// 向き

	uniqueOPRT _inputState;	// 入力情報取得変数
	ActionCtrl* _actCtrl;	// ｱｸｼｮﾝ制御用ｸﾗｽ変数
};

