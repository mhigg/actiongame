#pragma once
#include <cocos2d.h>
#include "ActionCtrl.h"

struct ActData;

struct JumpUp
{
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};

struct Jumping
{
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};