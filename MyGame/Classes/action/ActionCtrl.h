#pragma once
#include <functional>
#include <array>
#include <cocos2d.h>
#include "DIR.h"
#include "INPUT_ID.h"
#include "TIMING.h"

struct ActData;

// ����݂̊֐��߲���^
using ActFuncPtr = std::function<bool(cocos2d::Sprite&, ActData&)>;

enum class STATE
{
	MOVE,		// �ړ����
	JUMP,		// �ެ��ߏ��
	JUMPING,	// �ެ��ߒ�
	JUMPMOVE,	// �ެ��ߒ��ړ�
	FALL,		// �������
	FALLING,	// ������
	IDLE,		// ��~���
	MAX
};

struct ActData
{
	STATE state;						// ����݂̏�Ԗ�
	ActFuncPtr runAction;				// ���s���鱸��݂̊֐��߲��
	std::list<ActFuncPtr> act;			// ���s�O����������֐��߲��ؽ�
	std::list<STATE> blackList;			// ��ׯ�ؽ�(�J�ڕs�\�ȏ��ؽ�)
	std::list<STATE> whiteList;			// �ܲ�ؽ�(�J�ډ\�ȏ��ؽ�)
	cocos2d::Point distance;			// ����ݎ��̈ړ���
	std::array<cocos2d::Vec2, 2> col;	// ���S���瓖���蔻��̍��W�܂ł̒���(��/�E,��/��)
	DIR dir;							// ����
	INPUT_ID inputID;					// �Ή���
	TIMING timing;						// ���͂̏��
};

using ActVec = std::vector<ActFuncPtr>;
using ActMap = std::map<std::string, ActData>;

class ActionCtrl
	: public cocos2d::Ref
{
public:
	ActionCtrl();
	~ActionCtrl();

	// ����݂ɕK�v���ް��𱸼�ݖ����Ƃɓo�^����
	bool AddAction(const std::string actName, ActData& actData);
	// ����݂̍X�V����
	void Update(cocos2d::Sprite& sprite);

private:
	ActVec _actFuncList;		// State�ɉ���������݊֐��߲�����i�[����ؽ�
	ActMap _actMap;				// ������ް����i�[����A�z�z��
};