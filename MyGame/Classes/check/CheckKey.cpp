#include "CheckKey.h"
#include <unit/Player.h>

bool CheckKey::operator()(cocos2d::Sprite& sprite, ActData& actData)
{
	if (actData.inputID == INPUT_ID::NON)
	{
		return true;
	}
	// actDataのkeyCodeとそのtimingを見て、入力されたｷｰ情報と照らし合わせる
	// 一致すればtrue、一致しなければfalseを返す
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
