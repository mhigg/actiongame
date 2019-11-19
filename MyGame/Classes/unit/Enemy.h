#pragma once
#include <cocos2d.h>
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

	uniqueOPRT input;		// “ü—Íî•ñæ“¾•Ï”
};

