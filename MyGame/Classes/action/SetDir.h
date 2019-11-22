#pragma once
#include <cocos2d.h>

struct ActData;

struct SetDir
{
	// •ûŒü‚ð¾¯Ä‚µ‚ÄŒü‚«‚ð•Ï‚¦‚é
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};

