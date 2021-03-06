#pragma once
#include <cocos2d.h>
#include <action/ActionCtrl.h>
#include <input/OPRT_state.h>

class Enemy :
	public cocos2d::Sprite
{
public:
	static Enemy* createEnemy();

	Enemy();
	~Enemy();

	void update(float delta);

	// implement the "static create()" method manually
	CREATE_FUNC(Enemy);

private:
	void InitAction(void);		// ｱｸｼｮﾝの初期登録
	void InitAnimation(void);	// ｱﾆﾒｰｼｮﾝの初期登録

	std::string _nowActName;	// ｱｸｼｮﾝ状態名
	STATE _nowState;			// 現在のｱｸｼｮﾝ状態
	DIR _dir;					// 向き

	uniqueOPRT _inputState;		// 入力情報取得変数
	ActionCtrl* _actCtrl;		// ｱｸｼｮﾝ制御用ｸﾗｽ変数
};

