#include "CheckCollided.h"
#include <unit/Player.h>

USING_NS_CC;

bool CheckOverArea::operator()(cocos2d::Vec2 position, cocos2d::Vec2 areaLimit)
{
	//if ((0.0f < position.x) && (position.x < areaLimit.x)
	// && (0.0f < position.y) && (position.y < areaLimit.y));
	//{
	//	return true;
	//}
//	areaLimit = { 21, 12 };

	if (0.0f < position.x && position.x < areaLimit.x)
	{
		return true;
	}
	//if (0.0f < position.y && position.y < areaLimit.y)
	//{
	//	return true;
	//}
	return false;
}

bool CheckHitObj::operator()(Sprite& sprite, ActData& actData)
{
	// get mapChipData
	auto director = Director::getInstance();
	auto map = (TMXTiledMap*)director->getRunningScene()->getChildByName("groundLayer")->getChildByName("mapData");
	auto ground = map->getLayer("ground");
	auto mapSize = map->getMapSize();
	auto pos = ((Player&)sprite).getPosition();

	auto draw = DrawNode::create();
//	draw->drawSegment(actData.col[0], actData.col[1], 2.0f, Color4F::RED);
	draw->drawSegment(pos - Vec2(20, 0), pos + Vec2(20, 0), 2.0f, Color4F::RED);
	((Player&)sprite).addChild(draw);

	for (auto col : actData.col)
	{
		auto colPos = pos + col;
		auto mapPos = Vec2{
			colPos.x / map->getTileSize().width,
			colPos.y / map->getTileSize().height
		};
		if (!CheckOverArea()(mapPos, mapSize))
		{
			return false;
			break;
		}
	}
	

//	actData.col[0]

	//if (col->getTileGIDAt(rightpos) != 0
	//	|| col->getTileGIDAt(uprightpos) != 0
	//	|| col->getTileGIDAt(downrightpos) != 0)
	//{
	//	((Player&)sprite).setPosition(Vec2(tmpPos.x - actData.distance.x, tmpPos.y));
	//}

	//auto leftpos = Vec2((tmpPos.x - size.x / 2) / 48, tmpPos.y / 48);
	//auto upleftpos = Vec2((tmpPos.x - size.x / 2) / 48, mapSize.height - (tmpPos.y + size.y / 2) / 48);
	//auto downleftpos = Vec2((tmpPos.x - size.x / 2) / 48, mapSize.height - (tmpPos.y - size.y / 2) / 48);

	//if (col->getTileGIDAt(leftpos) != 0
	//	|| col->getTileGIDAt(upleftpos) != 0
	//	|| col->getTileGIDAt(downleftpos) != 0)
	//{
	//	((Player&)sprite).setPosition(Vec2(tmpPos.x + actData.distance.x, tmpPos.y));
	//}

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


void CheckHitSprites::operator()(Sprite * sprite1, Sprite * sprite2)
{
}