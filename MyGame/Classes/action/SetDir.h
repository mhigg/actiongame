#pragma once
#include <cocos2d.h>

struct ActData;

struct SetDir
{
	// ������Ă���
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};

