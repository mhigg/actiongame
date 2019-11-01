#pragma once
#include <array>
#include "cocos2d.h"
#include "2d/CCNode.h"
#include "DIR.h"

USING_NS_CC;

enum class OPRT_TYPE
{
	KEY,	// ·°ÎŞ°ÄŞ“ü—Í
	TOUCH,	// À¯ÁÊßÈÙ“ü—Í
	MAX
};

enum class TRG
{
	NOW,	// Œ»İ‚Ì“ü—Íî•ñ
	OLD,	// 1ÌÚ°Ñ‘O‚Ì“ü—Íî•ñ
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
	virtual void Init(Node* sp) = 0;			// “ü—Í”»’èˆ—Ò¿¯ÄŞ‚Ì‰Šú“o˜^
	virtual void UpdateOldInput(void) = 0;		// “ü—Íî•ñ‚ÌXVˆ—
	virtual const OPRT_TYPE GetType(void) = 0;	// “ü—Í‘•’u‚ÌÀ²Ìß‚ğæ“¾
	const InputAry & GetInputAry(void)			// Œ»İ‚Ì“ü—Íî•ñ‚ğæ“¾
	{
		return pressFlags;
	}

protected:
	InputAry pressFlags;	// Œ»İ‚Ì“ü—ÍÌ×¸Ş‚ğŠi”[
};
