#pragma once
#include <cocos2d.h>

struct ActData;

struct SetDir
{
	// 方向をｾｯﾄして向きを変える
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};

