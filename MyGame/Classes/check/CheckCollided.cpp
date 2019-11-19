#include "CheckCollided.h"
#include <unit/Player.h>

USING_NS_CC;


bool CheckHitObj::operator()(Sprite& sprite, ActData& actData)
{
	// get mapChipData
	auto director = Director::getInstance();
	auto map = (TMXTiledMap*)director->getRunningScene()->getChildByName("groundLayer")->getChildByName("mapData");
	auto col = map->getLayer("ground");
	auto mapSize = map->getMapSize();

	auto tmpPos = ((Player&)sprite).getPosition();
	auto size = Vec2{ 50,120 };

	auto rightpos = Vec2((tmpPos.x + size.x / 2) / 48, tmpPos.y / 48);
	auto uprightpos = Vec2((tmpPos.x + size.x / 2) / 48, mapSize.height - (tmpPos.y + size.y / 2) / 48);
	auto downrightpos = Vec2((tmpPos.x + size.x / 2) / 48, mapSize.height - (tmpPos.y - size.y / 2) / 48);

	if (col->getTileGIDAt(rightpos) != 0
		|| col->getTileGIDAt(uprightpos) != 0
		|| col->getTileGIDAt(downrightpos) != 0)
	{
		((Player&)sprite).setPosition(Vec2(tmpPos.x - actData.distance.x, tmpPos.y));
	}

	auto leftpos = Vec2((tmpPos.x - size.x / 2) / 48, tmpPos.y / 48);
	auto upleftpos = Vec2((tmpPos.x - size.x / 2) / 48, mapSize.height - (tmpPos.y + size.y / 2) / 48);
	auto downleftpos = Vec2((tmpPos.x - size.x / 2) / 48, mapSize.height - (tmpPos.y - size.y / 2) / 48);

	if (col->getTileGIDAt(leftpos) != 0
		|| col->getTileGIDAt(upleftpos) != 0
		|| col->getTileGIDAt(downleftpos) != 0)
	{
		((Player&)sprite).setPosition(Vec2(tmpPos.x + actData.distance.x, tmpPos.y));
	}

	//auto legpos = Vec2(tmpPos.x / 48, (mapSize.height - (tmpPos.y - size.y / 2) / 48));

	//if ((col->getTileGIDAt(downleftpos) != 0 && col->getTileGIDAt(legpos) != 0)
	//	|| (col->getTileGIDAt(downrightpos) != 0 && col->getTileGIDAt(legpos) != 0))
	//{
	//	((Player&)sprite).setPosition(Vec2(tmpPos.x, tmpPos.y + (tmpPos.y - ((mapSize.height - legpos.y) + 1) * 48)));
	//	gravity = false;
	//}

	//auto headpos = Vec2(tmpPos.x / 48, (mapSize.height - (tmpPos.y + size.y / 2) / 48));

	//if (col->getTileGIDAt(headpos) != 0)
	//{
	//	jumpFlag = false;
	//	((Player&)sprite).setPosition(Vec2(tmpPos.x, tmpPos.y - actData.distance.x));
	//}
	return true;
}

void CheckIsGround::operator()(Vec2 position, Vec2 gravity)
{
}

void CheckOverArea::operator()(Sprite * sprite)
{
}

void CheckHitSprites::operator()(Sprite * sprite1, Sprite * sprite2)
{
}