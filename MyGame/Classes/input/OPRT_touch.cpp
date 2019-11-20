#include "OPRT_touch.h"

void OPRT_touch::Init(cocos2d::Node* sp)
{
	// tap on device
	auto listener = cocos2d::EventListenerTouchOneByOne::create();

	listener->onTouchBegan = [this](cocos2d::Touch* touch, cocos2d::Event* event)->bool
	{
		// set first tap position
		auto loc = touch->getLocation();
		_startPoint = cocos2d::Point(loc.x, loc.y);

		return true;
	};
	listener->onTouchMoved = [this](cocos2d::Touch* touch, cocos2d::Event* event)->bool
	{
		// calculate inputID and set flag true

		int margin = 10;
		auto distance = touch->getLocation() - _startPoint;
		INPUT_ID inputX = INPUT_ID::NON, inputY = INPUT_ID::NON;

		if (distance.x > margin)
		{
			inputX = INPUT_ID::RIGHT;
		}
		else if (distance.x < -margin)
		{
			inputX = INPUT_ID::LEFT;
		}

		if (distance.y > margin)
		{
			inputY = INPUT_ID::UP;
		}
		else if (distance.y < -margin)
		{
			inputY = INPUT_ID::DOWN;
		}

		if (abs(distance.x) > abs(distance.y))
		{
			_pressFlags[static_cast<int>(inputX)][inputTrg] = true;
			_pressFlags[static_cast<int>(inputY)][inputTrg] = false;
		}
		else
		{
			_pressFlags[static_cast<int>(inputY)][inputTrg] = true;
			_pressFlags[static_cast<int>(inputX)][inputTrg] = false;
		}

		return true;
	};
	listener->onTouchEnded = [this](cocos2d::Touch* touch, cocos2d::Event* event)->bool
	{
		// set flag false

		for (int inputID = 0; inputID < static_cast<int>(INPUT_ID::MAX); inputID++)
		{
			_pressFlags[static_cast<int>(inputID)][inputTrg] = false;
		}

		return true;
	};

	sp->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, sp);
}

const OPRT_TYPE OPRT_touch::GetType(void)
{
	return OPRT_TYPE::TOUCH;
}
