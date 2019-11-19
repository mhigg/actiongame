#include "OPRT_touch.h"

void OPRT_touch::Init(cocos2d::Node* sp)
{
	// tap on device
	auto listener = cocos2d::EventListenerTouchOneByOne::create();

	listener->onTouchBegan = [this](cocos2d::Touch* touch, cocos2d::Event* event)->bool
	{
		// set first tap position
		auto loc = touch->getLocation();
		start = cocos2d::Point(loc.x, loc.y);

		return true;
	};
	listener->onTouchMoved = [this](cocos2d::Touch* touch, cocos2d::Event* event)->bool
	{
		// calculate dir and set flag true

		int margin = 10;
		auto distance = touch->getLocation() - start;
		DIR dirX = DIR::CENTER, dirY = DIR::CENTER;

		if (distance.x > margin)
		{
			dirX = DIR::RIGHT;
		}
		else if (distance.x < -margin)
		{
			dirX = DIR::LEFT;
		}

		if (distance.y > margin)
		{
			dirY = DIR::UP;
		}
		else if (distance.y < -margin)
		{
			dirY = DIR::DOWN;
		}

		if (abs(distance.x) > abs(distance.y))
		{
			pressFlags[static_cast<int>(dirX)][inputTrg] = true;
			pressFlags[static_cast<int>(dirY)][inputTrg] = false;
		}
		else
		{
			pressFlags[static_cast<int>(dirY)][inputTrg] = true;
			pressFlags[static_cast<int>(dirX)][inputTrg] = false;
		}

		return true;
	};
	listener->onTouchEnded = [this](cocos2d::Touch* touch, cocos2d::Event* event)->bool
	{
		// set flag false

		for (int dir = 0; dir < static_cast<int>(DIR::MAX); dir++)
		{
			pressFlags[static_cast<int>(dir)][inputTrg] = false;
		}

		return true;
	};

	sp->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, sp);
}

void OPRT_touch::Update(void)
{
	for (auto dir : DIR())
	{
		pressFlags[static_cast<int>(dir)][oldTrg] = pressFlags[static_cast<int>(dir)][nowTrg];
	}
	for (auto dir : DIR())
	{
		pressFlags[static_cast<int>(dir)][nowTrg] = pressFlags[static_cast<int>(dir)][inputTrg];
	}
}

const OPRT_TYPE OPRT_touch::GetType(void)
{
	return OPRT_TYPE::TOUCH;
}
