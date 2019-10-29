#include "CheckCollided.h"

USING_NS_CC;

void CheckHitObj::operator()(cocos2d::Vec2 position)
{
	//auto director = Director::getInstance();
	//auto map = (TMXTiledMap*)director->getRunningScene()->getChildByName("groundLay")->getChildByName("mapData");

	//auto col = map->getLayer("ground");

	//auto tmpPos = this->getPosition();
	//Vec2 size = { 50,120 };

	//auto mapSizeY = map->getMapSize().height;

	//auto uprightpos = Vec2((tmpPos.x + size.x) / 48, mapSizeY - (tmpPos.y + size.y / 2) / 48);
	//auto downrightpos = Vec2((tmpPos.x + size.x) / 48, mapSizeY - (tmpPos.y - size.y / 2) / 48);

	//if (col->getTileGIDAt(uprightpos) != 0 || col->getTileGIDAt(downrightpos) != 0)
	//{
	//	this->setPosition(Vec2(tmpPos.x - speed, tmpPos.y));
	//}

	//auto upleftpos = Vec2((tmpPos.x - size.x) / 48, mapSizeY - (tmpPos.y + size.y / 2) / 48);
	//auto downleftpos = Vec2((tmpPos.x - size.x) / 48, mapSizeY - (tmpPos.y - size.y / 2) / 48);

	//if (col->getTileGIDAt(upleftpos) != 0 || col->getTileGIDAt(downleftpos) != 0)
	//{
	//	this->setPosition(Vec2(tmpPos.x + speed, tmpPos.y));
	//}

	//auto legpos = Vec2((tmpPos.x) / 48, (mapSizeY - (tmpPos.y - size.y / 2) / 48));

	//if (col->getTileGIDAt(legpos) != 0)
	//{
	//	TRACE("leg.x:%f,leg.y:%f\n", legpos.x, legpos.y);
	//			jumpFlag = false;
	//	this->setPosition(Vec2(tmpPos.x, tmpPos.y + speed));
	//			this->setPosition(Vec2(legpos.x * 48, mapSizeY - size.y / 2 - (legpos.y + 1) * 48));
	//}

	//auto headpos = Vec2((tmpPos.x) / 48, (mapSizeY - (tmpPos.y + size.y / 2) / 48));

	//if (col->getTileGIDAt(headpos) != 0)
	//{
	//	jumpFlag = false;
	//	this->setPosition(Vec2(tmpPos.x, tmpPos.y - speed));
	//}
}
