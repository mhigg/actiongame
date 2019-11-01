#pragma once
#include <cocos2d.h>

struct CheckHitObj
{
	// 教咦材偲席踢偺摉偨傝敾掕
	void operator()(cocos2d::Vec2 position, cocos2d::Vec2 distance);
};

struct CheckIsGround
{
	void operator()(cocos2d::Vec2 position, cocos2d::Vec2 gravity);
};

struct CheckOverArea
{
	// 教咦材偺斖埻联
	void operator()(cocos2d::Sprite* sprite);
};

struct CheckHitSprites
{
	// 教咦材摨巑偺摉偨傝敾掕
	void operator()(cocos2d::Sprite* sprite1, cocos2d::Sprite* sprite2);
};