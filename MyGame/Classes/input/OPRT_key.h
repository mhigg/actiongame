#pragma once
#include "OPRT_state.h"

struct OPRT_key :
	public OPRT_state
{
	void Init(cocos2d::Node* sp)override;		// “ü—Í”»’èˆ—Ò¿¯ÄŞ‚Ì‰Šú“o˜^
	void Update(void)override;					// “ü—Íî•ñ‚ÌXVˆ—
	const OPRT_TYPE GetType(void)override;		// “ü—Í‘•’u‚ÌÀ²Ìß‚ğæ“¾
};

