#pragma once
#include <cocos2d.h>
#include "ActionCtrl.h"

struct ActData;

struct JumpUp
{
	// �ެ��ߊJ�n
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};

struct Jumping
{
	// �ެ��ߒ�
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};