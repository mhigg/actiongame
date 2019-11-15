#pragma once
#include <cocos2d.h>
#include <action/ActionCtrl.h>

struct ActData;

// ÌŞ×¯¸Ø½Ä‚ÆÎÜ²ÄØ½Ä‚ğg‚Á‚½”»’f
struct CheckList
{
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};

