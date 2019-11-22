#include "CheckCollided.h"
#include <unit/Player.h>

USING_NS_CC;

bool CheckOverArea::operator()(const cocos2d::Vec2& position, const cocos2d::Vec2& areaLimit)
{
	if ((0.0f <= position.x) && (position.x < areaLimit.x)
	 && (0.0f <= position.y) && (position.y < areaLimit.y))
	{
		return true;
	}
	return false;
}

bool CheckHitObj::operator()(Sprite& sprite, ActData& actData)
{
	auto director = Director::getInstance();
	auto map = (TMXTiledMap*)director->getRunningScene()->getChildByName("groundLayer")->getChildByName("mapData");
	auto ground = map->getLayer("ground");

	auto mapSize = map->getMapSize();
	auto tileSize = map->getTileSize();
	auto pos = ((Player&)sprite).getPosition();
	auto col1 = Vec2((pos.x + actData.col[0].x) / tileSize.width, mapSize.height - (pos.y + actData.col[0].y) / tileSize.height);
	auto col2 = Vec2((pos.x + actData.col[1].x) / tileSize.width, mapSize.height - (pos.y + actData.col[1].y) / tileSize.height);

	if (CheckOverArea()(col1, mapSize) && CheckOverArea()(col2, mapSize))
	{
		if (ground->getTileGIDAt(col1) == 0 && ground->getTileGIDAt(col2) == 0)
		{
			return true;
		}
	}

	return false;
}

void CheckHitSprites::operator()(const cocos2d::Sprite& sprite1, const cocos2d::Sprite& sprite2)
{
}
