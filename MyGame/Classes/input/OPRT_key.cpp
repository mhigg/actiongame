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
			_pressFlags[static_cast<int>(INPUT_ID::RIGHT)][inputTrg] = true;
		}
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW)
		{
			_pressFlags[static_cast<int>(INPUT_ID::LEFT)][inputTrg] = true;
		}
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW)
		{
			_pressFlags[static_cast<int>(INPUT_ID::UP)][inputTrg] = true;
		}
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW)
		{
			_pressFlags[static_cast<int>(INPUT_ID::DOWN)][inputTrg] = true;
		}
	};
	listener->onKeyReleased = [this](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
	{
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
		{
			_pressFlags[static_cast<int>(INPUT_ID::RIGHT)][inputTrg] = false;
		}
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW)
		{
			_pressFlags[static_cast<int>(INPUT_ID::LEFT)][inputTrg] = false;
		}
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW)
		{
			_pressFlags[static_cast<int>(INPUT_ID::UP)][inputTrg] = false;
		}
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW)
		{
			_pressFlags[static_cast<int>(INPUT_ID::DOWN)][inputTrg] = false;
		}
	};

	sp->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, sp);
}

const OPRT_TYPE OPRT_key::GetType(void)
{
	return OPRT_TYPE::KEY;
}
