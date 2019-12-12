#include "EffectMng.h"

USING_NS_CC;

EffectMng* EffectMng::s_instance = nullptr;

bool EffectMng::AddEffect(const std::string& key, const EffectData& effectData)
{
	if (_emitterMap.find(key) == _emitterMap.end())
	{
		auto effect = efk::Effect::create(effectData.efkName, 13.0f);
		if (effect != nullptr)
		{
			auto emitter = efk::EffectEmitter::create(effectData.effectMng);
			emitter->setEffect(effect);
			emitter->setPlayOnEnter(effectData.playOnEnter);
			emitter->setRotation3D(effectData.rotation);
			emitter->setPosition(effectData.position);
			emitter->setScale(effectData.scale);
			emitter->setRemoveOnStop(false);

			_emitterMap.emplace(key, emitter);
			return true;
		}
	}
	return false;
}

efk::EffectEmitter* EffectMng::GetEmitter(const std::string& key, const DIR dir, const Vec2& position)
{
	if (dir != DIR::CENTER)
	{
		_emitterMap[key]->setRotation3D(rotationAry[static_cast<int>(dir)]);
	}
	if (position != Vec2(-1, -1))
	{
		_emitterMap[key]->setPosition(position);
	}
	return _emitterMap[key];
}

EffectMng::EffectMng()
{
	rotationAry = {
		cocos2d::Vec3{0,-90,0},
		cocos2d::Vec3{0,90,0},
		cocos2d::Vec3{0,-90,0},
		cocos2d::Vec3{0,90,0},
		cocos2d::Vec3{0,0,0}
	};
}

EffectMng::~EffectMng()
{
}
