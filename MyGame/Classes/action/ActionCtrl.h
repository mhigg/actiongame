#pragma once
#include <functional>
#include <array>
#include <cocos2d.h>
#include "DIR.h"
#include <input/OPRT_state.h>

struct ActData;
enum class TIMING;

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
	std::array<cocos2d::Vec2, 2> col;	// ���S���瓖���蔻��̍��W�܂ł̒���(�����ɂ���ď㉺2����)
	DIR dir;							// ����
	TIMING timing;						// ���͂̏��
};

class ActionCtrl
{
public:
	ActionCtrl();
	~ActionCtrl();

	bool AddAction(const std::string actName, ActData& actData);
//	void SetAction(const );
	void Update(cocos2d::Sprite& sprite);

private:
	std::list<std::string> _stateNameList;	// ����ݏ�Ԗ����i�[����ؽ�
	std::vector<ActFuncPtr> _actFuncList;	// State�ɉ���������݊֐��߲�����i�[����ؽ�
	std::map<std::string, ActData> _actMap;	// ������ް����i�[����A�z�z��
	uniqueOPRT _inputState;					// ���͏��擾�ϐ�
};

