#pragma once
#include <cocos2d.h>
#include <action/ActionCtrl.h>

struct ActData;

// ��ׯ�ؽĂ��ܲ�ؽĂ��g�������f
struct CheckList
{
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};

