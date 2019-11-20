#pragma once
#include <cocos2d.h>

struct ActData;

struct FallDown
{
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};

struct Falling
{
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};