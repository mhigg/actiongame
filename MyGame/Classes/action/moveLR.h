#pragma once
#include <cocos2d.h>

struct ActData;

struct MoveLR
{
	// ���E�ړ�
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};

struct JumpLR
{
	// ���E�ړ�
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};

struct Idling
{
	// �ҋ@���
	bool operator()(cocos2d::Sprite& sprite, ActData& actData);
};