#pragma once
#include <cocos2d.h>

struct ActData;

struct MoveLR
{
	// ¶‰EˆÚ“®
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};

struct JumpLR
{
	// ¶‰EˆÚ“®
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};

struct Idling
{
	// ‘Ò‹@ó‘Ô
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};