#pragma once
#include <cocos2d.h>

struct ActData;

struct CheckHitObj
{
	// 懌応傗暻偲偄偭偨席踢偲偺摉偨傝敾掕
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};

struct CheckOverArea
{
	// 教咦材偺斖埻联
	bool operator()(cocos2d::Vec2 position, cocos2d::Vec2 areaLimit);
};

struct CheckIsGround
{
	void operator()(cocos2d::Vec2 position, cocos2d::Vec2 gravity);
};

struct CheckHitSprites
{
	// 教咦材摨巑偺摉偨傝敾掕
	void operator()(cocos2d::Sprite* sprite1, cocos2d::Sprite* sprite2);
};