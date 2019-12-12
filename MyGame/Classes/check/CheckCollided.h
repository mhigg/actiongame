#pragma once
#include <cocos2d.h>

struct ActData;

struct CheckOverArea
{
	// ���ײĂ͈̔�����
	bool operator()(const cocos2d::Vec2& position, const cocos2d::Vec2& areaLimit);
};

struct CheckHitObj
{
	// �����ǂƂ�����ϯ�߂Ƃ̓����蔻��
	// �������Ă�����false��Ԃ�
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};

struct CheckHitSprites
{
	// ���ײē��m�̓����蔻��
	void operator()(const cocos2d::Sprite& sprite1, const cocos2d::Sprite& sprite2);
};