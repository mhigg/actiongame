#include "CheckKey.h"
#include <unit/Player.h>

bool CheckKey::operator()(cocos2d::Sprite& sprite, ActData& actData)
{
	if (actData.inputID == INPUT_ID::NON)
	{
		return true;
	}
	// actData‚ÌkeyCode‚Æ‚»‚Ìtiming‚ðŒ©‚ÄA“ü—Í‚³‚ê‚½·°î•ñ‚ÆÆ‚ç‚µ‡‚í‚¹‚é
	// ˆê’v‚·‚ê‚ÎtrueAˆê’v‚µ‚È‚¯‚ê‚Îfalse‚ð•Ô‚·
	auto input = ((Player&)sprite).inputState()->GetInputAry();
	auto dir = actData.inputID;
	TIMING compared;

	if (input[static_cast<int>(dir)][nowTrg])
	{
		compared = TIMING::ON;
		if (!input[static_cast<int>(dir)][oldTrg])
		{
			compared = TIMING::ON_MOM;
		}
	}
	else
	{
		compared = TIMING::OFF;
		if (input[static_cast<int>(dir)][oldTrg])
		{
			compared = TIMING::OFF_MOM;
		}
	}

	return (actData.timing == compared);
}
