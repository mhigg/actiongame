#include "CheckKey.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include <input/OPRT_key.h>
#else
#include <input/OPRT_touch.h>
#endif

bool CheckKey::operator()(cocos2d::Sprite& sprite, ActData& actData)
{
	// actDataのkeyCodeとそのtimingを見て、入力されたｷｰ情報と照らし合わせる
	// 一致すればtrue、一致しなければfalseを返す
	return false;
}
