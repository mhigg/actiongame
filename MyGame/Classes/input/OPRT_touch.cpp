#include "OPRT_touch.h"


void OPRT_touch::Init(Node* sp)
{
	// tap on device
	auto listener = cocos2d::EventListenerTouchOneByOne::create();

	listener->onTouchBegan = [this](cocos2d::Touch* touch, cocos2d::Event* event)->bool
	{
		// set first tap position
		auto loc = touch->getLocation();
		start = Point(loc.x, loc.y);

		return true;
	};
	listener->onTouchMoved = [this](cocos2d::Touch* touch, cocos2d::Event* event)->bool
	{
		// calculate dir and set flag true

		int margin = 10;
		auto loc = touch->getLocation();
		DIR dir = DIR::CENTER, dirX = DIR::CENTER, dirY = DIR::CENTER;

		if (loc.x - start.x > margin)
		{
			dirX = DIR::RIGHT;
		}
		else if (loc.x - start.x < -margin)
		{
			dirX = DIR::LEFT;
		}
		if (loc.y - start.y > margin)
		{
			dirY = DIR::UP;
		}
		else if (loc.y - start.y < -margin)
		{
			dirY = DIR::DOWN;
		}

		if (abs(loc.x - start.x) > abs(loc.y - start.y))
		{
			dir = dirX;
		}
		else if (abs(loc.x - start.x) < abs(loc.y - start.y))
		{
			dir = dirY;
		}
		else
		{
			dir = DIR::CENTER;
		}

		pressFlags[static_cast<int>(dir)].first = true;

		return true;
	};
	listener->onTouchEnded = [this](cocos2d::Touch* touch, cocos2d::Event* event)->bool
	{
		// set flag false

		for (int dir = 0; dir < static_cast<int>(DIR::MAX); dir++)
		{
			pressFlags[static_cast<int>(dir)].first = false;
		}

		return true;
	};

	sp->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, sp);
}

void OPRT_touch::UpDate(void)
{
}

const OPRT_TYPE OPRT_touch::GetType(void)
{
	return OPRT_TYPE::TOUCH;
}
