#include "CheckList.h"
#include <unit/Player.h>

bool CheckList::operator()(cocos2d::Sprite& sprite, ActData& actData)
{
	for (auto blackAct : actData.blackList)
	{
		if (((Player&)sprite).nowState() == blackAct)
		{
			return false;
		}
	}

	for (auto whiteAct : actData.whiteList)
	{
		if (((Player&)sprite).nowState() == whiteAct)
		{
			return true;
		}
	}

	if (actData.whiteList.size() > 0)
	{
		return false;
	}

	return true;
}
