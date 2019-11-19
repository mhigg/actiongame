#pragma once
#include <cocos2d.h>
#include "ActionCtrl.h"

struct ActData;

struct jumpUp
{
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};

struct jumping
{
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};