#pragma once
#include <array>
#include <cocos2d.h>
#include "2d/CCNode.h"
#include "DIR.h"

enum class OPRT_TYPE
{
	KEY,	// ·°ÎŞ°ÄŞ“ü—Í
	TOUCH,	// À¯ÁÊßÈÙ“ü—Í
	MAX
};

enum class TIMING
{
	ON,			// ‰Ÿ‚µ‚Ä‚¢‚éŠÔ
	ON_MOM,		// ‰Ÿ‚µ‚½uŠÔ
	OFF,		// —£‚µ‚Ä‚¢‚éŠÔ
	OFF_MOM		// —£‚µ‚½uŠÔ
};

enum class TRG
{
	NOW,	// Œ»İ‚Ì“ü—Íî•ñ
	OLD,	// 1ÌÚ°Ñ‘O‚Ì“ü—Íî•ñ
	INPUT,	// “ü—Í‚³‚ê‚½¶‚Ì“ü—Íî•ñ
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
	OPRT_state(void)
	{
		for (auto dir : DIR())
		{
			pressFlags[static_cast<int>(dir)] = { false, false, false };
		}
	};
	virtual void Init(cocos2d::Node* sp) = 0;	// “ü—Í”»’èˆ—Ò¿¯ÄŞ‚Ì‰Šú“o˜^
	virtual void Update(void) = 0;				// “ü—Íî•ñ‚ÌXVˆ—
	virtual const OPRT_TYPE GetType(void) = 0;	// “ü—Í‘•’u‚ÌÀ²Ìß‚ğæ“¾
	const InputAry & GetInputAry(void)			// Œ»İ‚Ì“ü—Íî•ñ‚ğæ“¾
	{
		return pressFlags;
	}

protected:
	InputAry pressFlags;	// Œ»İ‚Ì“ü—ÍÌ×¸Ş‚ğŠi”[
};
