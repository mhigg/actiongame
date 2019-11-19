#pragma once
#include <cocos2d.h>

struct ActData;

struct SetDir
{
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};

