#pragma once
#include <cocos2d.h>
#include "ActionCtrl.h"

struct ActData;

struct JumpUp
{
	// ¼Þ¬ÝÌßŠJŽn
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};

struct Jumping
{
	// ¼Þ¬ÝÌß’†
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};