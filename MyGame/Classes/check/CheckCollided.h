#pragma once
#include <cocos2d.h>

struct ActData;

struct CheckOverArea
{
	// 教咦材偺斖埻联
	bool operator()(const cocos2d::Vec2& position, const cocos2d::Vec2& areaLimit);
};

struct CheckHitObj
{
	// 懌応傗暻偲偄偭偨席踢偲偺摉偨傝敾掕
	// 摉偨偭偰偄偨傜false傪曉偡
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};

struct CheckHitSprites
{
	// 教咦材摨巑偺摉偨傝敾掕
	void operator()(const cocos2d::Sprite& sprite1, const cocos2d::Sprite& sprite2);
};