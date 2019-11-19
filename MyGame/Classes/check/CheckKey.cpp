#include "CheckKey.h"
#include <unit/Player.h>

bool CheckKey::operator()(cocos2d::Sprite& sprite, ActData& actData)
{
	// actData‚ÌkeyCode‚Æ‚»‚Ìtiming‚ðŒ©‚ÄA“ü—Í‚³‚ê‚½·°î•ñ‚ÆÆ‚ç‚µ‡‚í‚¹‚é
	// ˆê’v‚·‚ê‚ÎtrueAˆê’v‚µ‚È‚¯‚ê‚Îfalse‚ð•Ô‚·
	auto input = ((Player&)sprite).inputState()->GetInputAry();
	auto dir = ((Player&)sprite).dir();
	TIMING compared;

	if (input[static_cast<int>(dir)][nowTrg])
	{
		if (!input[static_cast<int>(dir)][oldTrg])
		{
			compared = TIMING::ON_MOM;
		}
		else
		{
			compared = TIMING::ON;
		}
	}
	else
	{
		if (input[static_cast<int>(dir)][oldTrg])
		{
			compared = TIMING::OFF_MOM;
		}
		else
		{
			compared = TIMING::OFF;
		}
	}

	return (actData.timing == compared);
}
