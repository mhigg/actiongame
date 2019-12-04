#include "CheckKey.h"
#include <unit/Player.h>

bool CheckKey::operator()(cocos2d::Sprite& sprite, ActData& actData)
{
	if (actData.inputID == INPUT_ID::NON)
	{
		return true;
	}
	// actData��keyCode�Ƃ���timing�����āA���͂��ꂽ�����ƏƂ炵���킹��
	// ��v�����true�A��v���Ȃ����false��Ԃ�
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
