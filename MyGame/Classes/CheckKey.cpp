#include "CheckKey.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include <input/OPRT_key.h>
#else
#include <input/OPRT_touch.h>
#endif

bool CheckKey::operator()(cocos2d::Sprite& sprite, ActData& actData)
{
	// actData��keyCode�Ƃ���timing�����āA���͂��ꂽ�����ƏƂ炵���킹��
	// ��v�����true�A��v���Ȃ����false��Ԃ�
	return false;
}
