#pragma once
#include "OPRT_state.h"

struct OPRT_key :
	public OPRT_state
{
	void Init(cocos2d::Node* sp)override;		// ���͔��菈��ҿ��ނ̏����o�^
	const OPRT_TYPE GetType(void)override;		// ���͑��u�����߂��擾
};

