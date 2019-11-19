#include "OPRT_key.h"

// ���͔��菈��ҿ��ނ̏����o�^
// sp �c ҿ��ނ�o�^������ײ�
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

const OPRT_TYPE OPRT_key::GetType(void)
{
	return OPRT_TYPE::KEY;
}
