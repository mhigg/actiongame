#pragma once
#include <cocos2d.h>

// 教咦材偲席踢偺摉偨傝敾掕
struct CheckHitObj
{
	void operator()(cocos2d::Vec2 position, cocos2d::Vec2 distance);
};

// 教咦材偺斖埻联
struct CheckOverArea
{
	void operator()(cocos2d::Sprite* sprite);
};

// 教咦材摨巑偺摉偨傝敾掕
struct CheckHitSprites
{
	void operator()(cocos2d::Sprite* sprite1, cocos2d::Sprite* sprite2);
};