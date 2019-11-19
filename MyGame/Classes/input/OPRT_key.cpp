#include "OPRT_key.h"

// “ü—Í”»’èˆ—Ò¿¯ÄÞ‚Ì‰Šú“o˜^
// sp c Ò¿¯ÄÞ‚ð“o˜^‚·‚é½Ìß×²Ä
void OPRT_key::Init(cocos2d::Node* sp)
{
	// pushing keys

	auto listener = cocos2d::EventListenerKeyboard::create();

	listener->onKeyPressed = [this](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
	{
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
		{
			pressFlags[static_cast<int>(DIR::RIGHT)][inputTrg] = true;
		}
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW)
		{
			pressFlags[static_cast<int>(DIR::LEFT)][inputTrg] = true;
		}
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW)
		{
			pressFlags[static_cast<int>(DIR::UP)][inputTrg] = true;
		}
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW)
		{
			pressFlags[static_cast<int>(DIR::DOWN)][inputTrg] = true;
		}
	};
	listener->onKeyReleased = [this](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
	{
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
		{
			pressFlags[static_cast<int>(DIR::RIGHT)][inputTrg] = false;
		}
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW)
		{
			pressFlags[static_cast<int>(DIR::LEFT)][inputTrg] = false;
		}
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW)
		{
			pressFlags[static_cast<int>(DIR::UP)][inputTrg] = false;
		}
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW)
		{
			pressFlags[static_cast<int>(DIR::DOWN)][inputTrg] = false;
		}
	};

	sp->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, sp);
}

void OPRT_key::Update(void)
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

const OPRT_TYPE OPRT_key::GetType(void)
{
	return OPRT_TYPE::KEY;
}
