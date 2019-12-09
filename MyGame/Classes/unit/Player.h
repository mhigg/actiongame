#pragma once
#include <cocos2d.h>
#include <action/ActionCtrl.h>
#include <input/OPRT_state.h>

class Player :
	public cocos2d::Sprite
{
public:
	static Player* createPlayer();

	Player();
	~Player();

	void update(float delta);	// 更新処理
	
	const STATE nowState(void) const;			// 現在のｱｸｼｮﾝ状態を取得する
	void nowState(const STATE state);			// 現在のｱｸｼｮﾝ状態をｾｯﾄする
	const cocos2d::Vec2 jumpSpeed(void) const;	// 現在のｼﾞｬﾝﾌﾟ速度を取得する
	void jumpSpeed(const cocos2d::Vec2 speed);	// 現在のｼﾞｬﾝﾌﾟ速度をｾｯﾄする
	const DIR dir(void) const;					// 向きを取得する
	void dir(const DIR direction);				// 向きをｾｯﾄする
	const uniqueOPRT& inputState(void);			// 入力情報を取得する

	// implement the "static create()" method manually
	CREATE_FUNC(Player);

private:
	void InitAction(void);		// ｱｸｼｮﾝの初期登録
	void InitAnimation(void);	// ｱﾆﾒｰｼｮﾝの初期登録

	std::string _nowActName;	// ｱｸｼｮﾝ状態名
	STATE _nowState;			// 現在のｱｸｼｮﾝ状態
	STATE _oldState;			// 1ﾌﾚｰﾑ前のｱｸｼｮﾝ状態
	DIR _dir;					// 向き
	float _gravity;				// 重力
	cocos2d::Vec2 _jumpSpeed;	// ｼﾞｬﾝﾌﾟ時のｽﾋﾟｰﾄﾞ

	uniqueOPRT _inputState;		// 入力情報取得変数
	ActionCtrl* _actCtrl;		// ｱｸｼｮﾝ制御用ｸﾗｽ変数
};