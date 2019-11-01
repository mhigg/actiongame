#pragma once
#include <cocos2d.h>

struct CheckHitObj
{
	// ���ײĂ�ϯ�߂̓����蔻��
	void operator()(cocos2d::Vec2 position, cocos2d::Vec2 distance);
};

struct CheckIsGround
{
	void operator()(cocos2d::Vec2 position, cocos2d::Vec2 gravity);
};

struct CheckOverArea
{
	// ���ײĂ͈̔�����
	void operator()(cocos2d::Sprite* sprite);
};

struct CheckHitSprites
{
	// ���ײē��m�̓����蔻��
	void operator()(cocos2d::Sprite* sprite1, cocos2d::Sprite* sprite2);
};