#pragma once
#include <cocos2d.h>

struct ActData;

struct fallDown
{
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};

struct falling
{
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};