#include "OPRT_key.h"


// “ü—Í”»’èˆ—Ò¿¯ÄÞ‚Ì‰Šú“o˜^
// sp c Ò¿¯ÄÞ‚ð“o˜^‚·‚é½Ìß×²Ä
void OPRT_key::Init(Node* sp)
{
	// pushing keys

	auto listener = cocos2d::EventListenerKeyboard::create();

	listener->onKeyPressed = [this](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
	{
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
		{
			pressFlags[static_cast<int>(DIR::RIGHT)].first  = true;
			pressFlags[static_cast<int>(DIR::RIGHT)].second = false;
		}
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW)
		{
			pressFlags[static_cast<int>(DIR::LEFT)].first  = true;
			pressFlags[static_cast<int>(DIR::LEFT)].second = false;
		}
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW)
		{
			pressFlags[static_cast<int>(DIR::UP)].first  = true;
			pressFlags[static_cast<int>(DIR::UP)].second = false;
		}
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW)
		{
			pressFlags[static_cast<int>(DIR::DOWN)].first  = true;
			pressFlags[static_cast<int>(DIR::DOWN)].second = false;
		}
	};
	listener->onKeyReleased = [this](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
	{
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
		{
			pressFlags[static_cast<int>(DIR::RIGHT)].first  = false;
			pressFlags[static_cast<int>(DIR::RIGHT)].second = true;
		}
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW)
		{
			pressFlags[static_cast<int>(DIR::LEFT)].first  = false;
			pressFlags[static_cast<int>(DIR::LEFT)].second = true;
		}
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW)
		{
			pressFlags[static_cast<int>(DIR::UP)].first  = false;
			pressFlags[static_cast<int>(DIR::UP)].second = true;
		}
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW)
		{
			pressFlags[static_cast<int>(DIR::DOWN)].first  = false;
			pressFlags[static_cast<int>(DIR::DOWN)].second = true;
		}
	};

	sp->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, sp);
}

void OPRT_key::UpdateOldInput(void)
{
	for (auto dir : DIR())
	{
		pressFlags[static_cast<int>(dir)].second = pressFlags[static_cast<int>(dir)].first;
	}
}

const OPRT_TYPE OPRT_key::GetType(void)
{
	return OPRT_TYPE::KEY;
}
