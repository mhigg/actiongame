#pragma once
#include <functional>
#include <cocos2d.h>
#include "DIR.h"
#include <input/OPRT_state.h>

struct ActData;

using ActFuncPtr = std::function<bool(cocos2d::Sprite&, ActData&)>;

enum class State
{
	idle,	// ��~���
	move,	// �ړ����
	jump,	// �ެ��ߏ��
	max
};

struct ActData
{
	State state;						// ����݂̏�Ԗ�
	ActFuncPtr runAction;				// ���s���鱸��݂̊֐��߲��
	std::list<ActFuncPtr> act;			// ���s�O����������֐��߲��ؽ�
	std::list<State> blackList;			// ��ׯ�ؽ�(�J�ڕs�\�ȏ��ؽ�)
	std::list<State> whiteList;			// �ܲ�ؽ�(�J�ډ\�ȏ��ؽ�)
	cocos2d::Point distance;			// ����ݎ��̈ړ���
	DIR dir;							// ����
	TIMING timing;						// 
};

class ActionCtrl
{
public:
	ActionCtrl();
	~ActionCtrl();

	bool AddAction(const std::string actName, ActData& actData);
	void Update(void);

private:
	bool CheckHitObj(cocos2d::Sprite& sprite, ActData& actData);	// �����ǂƂ�����ϯ�߂Ƃ̓����蔻��

	std::list<std::string> _stateNameList;	// ����ݏ�Ԗ����i�[����ؽ�
	std::map<std::string, ActData> actMap;	// ������ް����i�[����A�z�z��

};

