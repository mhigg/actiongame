#pragma once
#include <memory>
#include <array>
#include <cocos2d.h>
#include <Effekseer/Effekseer.h>
#include "DIR.h"

#define lpEffectMng EffectMng::GetInstance()

struct EffectData
{
	efk::EffectManager* effectMng;
	std::string efkName;
	bool playOnEnter;
	cocos2d::Vec3 rotation;
	cocos2d::Vec2 position;
	float scale;
};

class EffectMng
{
public:
	static EffectMng& GetInstance(void)
	{
		if (s_instance == nullptr)
		{
			s_instance = new EffectMng();
		}
		return (*s_instance);
	}

	bool AddEffect(const std::string& key, const EffectData& effectData);
	efk::EffectEmitter* GetEmitter(
		const std::string& key,
		const DIR dir = DIR::CENTER,
		const cocos2d::Vec2& position = cocos2d::Vec2(-1, -1)
	);

private:
	EffectMng();
	~EffectMng();

	std::array<cocos2d::Vec3, static_cast<int>(DIR::MAX)> rotationAry;
	std::map<std::string, efk::EffectEmitter*> _emitterMap;
	static EffectMng* s_instance;
};

