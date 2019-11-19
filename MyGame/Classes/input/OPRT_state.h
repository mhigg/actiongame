#pragma once
#include <array>
#include <cocos2d.h>
#include "2d/CCNode.h"
#include "DIR.h"

enum class OPRT_TYPE
{
	KEY,	// ���ް�ޓ���
	TOUCH,	// ������ٓ���
	MAX
};

enum class TIMING
{
	ON,			// �����Ă����
	ON_MOM,		// �������u��
	OFF,		// �����Ă����
	OFF_MOM		// �������u��
};

enum class TRG
{
	NOW,	// ���݂̓��͏��
	OLD,	// 1�ڰёO�̓��͏��
	INPUT,	// ���͂��ꂽ���̓��͏��
	MAX
};

#define nowTrg static_cast<int>(TRG::NOW)
#define oldTrg static_cast<int>(TRG::OLD)
#define inputTrg static_cast<int>(TRG::INPUT)

struct OPRT_state;

using TrgAry = std::array<bool, static_cast<int>(TRG::MAX)>;
using InputAry = std::array<TrgAry, static_cast<int>(DIR::MAX)>;
using uniqueOPRT = std::unique_ptr<OPRT_state>;

struct OPRT_state
{
	OPRT_state(void);
	virtual void Init(cocos2d::Node* sp) = 0;	// ���͔��菈��ҿ��ނ̏����o�^
	virtual void Update(void);					// ���͏��̍X�V����
	const InputAry& GetInputAry(void);			// ���݂̓��͏����擾
	virtual const OPRT_TYPE GetType(void) = 0;	// ���͑��u�����߂��擾

protected:
	InputAry pressFlags;	// ���݂̓����׸ނ��i�[
};
