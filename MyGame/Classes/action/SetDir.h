#pragma once
#include <cocos2d.h>

struct ActData;

struct SetDir
{
	// •ûŒü‚ð¾¯Ä‚·‚é
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};

