#pragma once
#include <cocos2d.h>

struct ActData;

struct MoveLR
{
	// 左右移動
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};

struct Idling
{
	// 待機状態
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};