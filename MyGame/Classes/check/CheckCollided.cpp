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

	for (int colIdx = 0; colIdx < actData.col.size(); colIdx++)
	{
		auto col = Vec2((pos.x + actData.col[colIdx].x) / tileSize.width, mapSize.height - (pos.y + actData.col[colIdx].y) / tileSize.height);
		if (!CheckOverArea()(col, mapSize))
		{
			if (((Player&)sprite).nowState() == STATE::JUMPING)
			{
				((Player&)sprite).nowState(STATE::FALL);
			}
			if (((Player&)sprite).nowState() == STATE::FALLING)
			{
				((Player&)sprite).nowState(STATE::IDLE);
			}
			return false;
		}
		if (ground->getTileGIDAt(col) != 0)
		{
			if (((Player&)sprite).nowState() == STATE::JUMPING)
			{
				((Player&)sprite).nowState(STATE::FALL);
			}
			if (((Player&)sprite).nowState() == STATE::FALLING)
			{
				((Player&)sprite).nowState(STATE::IDLE);
			}
			return false;
		}
	}

	return true;
}

void CheckHitSprites::operator()(const cocos2d::Sprite& sprite1, const cocos2d::Sprite& sprite2)
{
}
