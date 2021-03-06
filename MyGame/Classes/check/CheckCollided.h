#pragma once
#include <cocos2d.h>

struct ActData;

struct CheckOverArea
{
	// ｽﾌﾟﾗｲﾄの範囲ﾁｪｯｸ
	bool operator()(const cocos2d::Vec2& position, const cocos2d::Vec2& areaLimit);
};

struct CheckHitObj
{
	// 足場や壁といったﾏｯﾌﾟとの当たり判定
	// 当たっていたらfalseを返す
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};

struct CheckHitSprites
{
	// ｽﾌﾟﾗｲﾄ同士の当たり判定
	void operator()(const cocos2d::Sprite& sprite1, const cocos2d::Sprite& sprite2);
};