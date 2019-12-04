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
	void InitAction(void);		// ±¸¼®İ‚Ì‰Šú“o˜^
	void InitAnimation(void);	// ±ÆÒ°¼®İ‚Ì‰Šú“o˜^

	std::string _nowActName;	// ±¸¼®İó‘Ô–¼
	STATE _nowState;			// Œ»İ‚Ì±¸¼®İó‘Ô
	DIR _dir;					// Œü‚«

	uniqueOPRT _inputState;		// “ü—Íî•ñæ“¾•Ï”
	ActionCtrl* _actCtrl;		// ±¸¼®İ§Œä—p¸×½•Ï”
};

