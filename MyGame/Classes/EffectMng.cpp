//#include "EffectMng.h"
//
//USING_NS_CC;
//
//EffectMng* EffectMng::s_instance = nullptr;
//
//void EffectMng::AddEffect(const std::string & effectName, bool playOnEnter, cocos2d::Vec2 position, float scale)
//{
//	_emitterMap.emplace(effectName, efk::EffectEmitter::create(efk::EffectManager::create(Director::getInstance()->getVisibleSize())));
//	auto effect = efk::Effect::create(effectName);
//	_emitterMap[effectName]->setEffect(effect);
//	_emitterMap[effectName]->setPlayOnEnter(playOnEnter);
//	_emitterMap[effectName]->setPosition(position);
//	_emitterMap[effectName]->setScale(scale);
//}
//
//efk::EffectEmitter& EffectMng::GetEmitter(const std::string& effectName)
//{
//	return (*_emitterMap[effectName]);
//}
//
//EffectMng::EffectMng()
//{
//}
//
//EffectMng::~EffectMng()
//{
//}
