#pragma once
#include "OPRT_state.h"

struct OPRT_key :
	public OPRT_state
{
	void Init(Node* sp)override;				// ���͔��菈��ҿ��ނ̏����o�^
	void UpdateOldInput(void)override;			// ���͏��̍X�V����
	const OPRT_TYPE GetType(void)override;		// ���͑��u�����߂��擾
};

