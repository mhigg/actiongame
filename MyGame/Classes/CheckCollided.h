#pragma once
#include <cocos2d.h>

// ���ײĂ�ϯ�߂̓����蔻��
struct CheckHitObj
{
	void operator()(cocos2d::Vec2 position, cocos2d::Vec2 distance);
};

// ���ײĂ͈̔�����
struct CheckOverArea
{
	void operator()(cocos2d::Sprite* sprite);
};

// ���ײē��m�̓����蔻��
struct CheckHitSprites
{
	void operator()(cocos2d::Sprite* sprite1, cocos2d::Sprite* sprite2);
};