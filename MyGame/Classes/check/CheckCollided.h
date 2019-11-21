#pragma once
#include <cocos2d.h>

struct ActData;

struct CheckHitObj
{
	// �����ǂƂ�����ϯ�߂Ƃ̓����蔻��
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};

struct CheckOverArea
{
	// ���ײĂ͈̔�����
	bool operator()(cocos2d::Vec2 position, cocos2d::Vec2 areaLimit);
};

struct CheckIsGround
{
	void operator()(cocos2d::Vec2 position, cocos2d::Vec2 gravity);
};

struct CheckHitSprites
{
	// ���ײē��m�̓����蔻��
	void operator()(cocos2d::Sprite* sprite1, cocos2d::Sprite* sprite2);
};