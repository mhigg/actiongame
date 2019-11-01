#pragma once
#include <array>
#include "cocos2d.h"
#include "2d/CCNode.h"
#include "DIR.h"

USING_NS_CC;

enum class OPRT_TYPE
{
	KEY,	// ���ް�ޓ���
	TOUCH,	// ������ٓ���
	MAX
};

enum class TRG
{
	NOW,	// ���݂̓��͏��
	OLD,	// 1�ڰёO�̓��͏��
	MAX
};

class OPRT_state;

using NowOld = std::pair<bool, bool>;
using InputAry = std::array<NowOld, static_cast<int>(DIR::MAX)>;
using uniqueOPRT = std::unique_ptr<OPRT_state>;

struct OPRT_state
{
	OPRT_state(void)
	{
		pressFlags = {
			NowOld{false,false},
			NowOld{false,false},
			NowOld{false,false},
			NowOld{false,false},
			NowOld{false,false}
		};
	};
	virtual void Init(Node* sp) = 0;			// ���͔��菈��ҿ��ނ̏����o�^
	virtual void UpdateOldInput(void) = 0;		// ���͏��̍X�V����
	virtual const OPRT_TYPE GetType(void) = 0;	// ���͑��u�����߂��擾
	const InputAry & GetInputAry(void)			// ���݂̓��͏����擾
	{
		return pressFlags;
	}

protected:
	InputAry pressFlags;	// ���݂̓����׸ނ��i�[
};
