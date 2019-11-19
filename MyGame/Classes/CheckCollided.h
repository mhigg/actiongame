#pragma once
#include <cocos2d.h>

struct ActData;

struct CheckHitObj
{
	// 足場や壁といったﾏｯﾌﾟとの当たり判定
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};

struct CheckIsGround
{
	void operator()(cocos2d::Vec2 position, cocos2d::Vec2 gravity);
};

struct CheckOverArea
{
	// ｽﾌﾟﾗｲﾄの範囲ﾁｪｯｸ
	void operator()(cocos2d::Sprite* sprite);
};

struct CheckHitSprites
{
	// ｽﾌﾟﾗｲﾄ同士の当たり判定
	void operator()(cocos2d::Sprite* sprite1, cocos2d::Sprite* sprite2);
};