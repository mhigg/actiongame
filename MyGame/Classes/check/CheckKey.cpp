#include "CheckKey.h"
#include <unit/Player.h>

bool CheckKey::operator()(cocos2d::Sprite& sprite, ActData& actData)
{
	// actDataのkeyCodeとそのtimingを見て、入力されたｷｰ情報と照らし合わせる
	// 一致すればtrue、一致しなければfalseを返す
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
