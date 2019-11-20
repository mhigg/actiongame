#pragma once
#include "OPRT_state.h"

struct OPRT_touch :
	public OPRT_state
{
	void Init(cocos2d::Node* sp)override;		// “ü—Í”»’èˆ—Ò¿¯ÄŞ‚Ì‰Šú“o˜^
	const OPRT_TYPE GetType(void)override;		// “ü—Í‘•’u‚ÌÀ²Ìß‚ğæ“¾

private:
	cocos2d::Point _startPoint;
};

