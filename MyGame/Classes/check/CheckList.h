#pragma once
#include <cocos2d.h>

struct ActData;

// ��ׯ�ؽĂ��ܲ�ؽĂ��g�������f
struct CheckList
{
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};

