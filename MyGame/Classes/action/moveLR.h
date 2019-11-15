#pragma once
#include <cocos2d.h>
#include "ActionCtrl.h"

struct ActData;

struct moveLR
{
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};

