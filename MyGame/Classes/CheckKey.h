#pragma once
#include <cocos2d.h>

struct ActData;

struct CheckKey
{
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};

