#include "moveLR.h"
#include <unit/Player.h>
#include "SoundMng.h"
//#include <_DebugConOut.h>

bool MoveLR::operator()(cocos2d::Sprite& sprite, ActData& actData)
{
	SOUND("walk")[0]->play();
	//TRACE("move\n");
	((Player&)sprite).setPosition(((Player&)sprite).getPosition() + actData.distance);
	return true;
}

bool Idling::operator()(cocos2d::Sprite& sprite, ActData& actData)
{
	//TRACE("idle\n");
	((Player&)sprite).nowState(STATE::IDLE);
	return true;
}
