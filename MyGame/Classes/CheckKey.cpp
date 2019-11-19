#include "CheckKey.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include <input/OPRT_key.h>
#else
#include <input/OPRT_touch.h>
#endif

bool CheckKey::operator()(cocos2d::Sprite& sprite, ActData& actData)
{
	// actData‚ÌkeyCode‚Æ‚»‚Ìtiming‚ğŒ©‚ÄA“ü—Í‚³‚ê‚½·°î•ñ‚ÆÆ‚ç‚µ‡‚í‚¹‚é
	// ˆê’v‚·‚ê‚ÎtrueAˆê’v‚µ‚È‚¯‚ê‚Îfalse‚ğ•Ô‚·
	return false;
}
