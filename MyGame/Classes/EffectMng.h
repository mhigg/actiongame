#pragma once
#include <memory>
#include <cocos2d.h>
#include <Effekseer/Effekseer.h>

#define lpEffectMng EffectMng::GetInstance()

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

	void AddEffect(const std::string& effectName, bool playOnEnter, cocos2d::Vec2 position, float scale);
	efk::EffectEmitter& GetEmitter(const std::string& effectName);

private:
	EffectMng();
	~EffectMng();

	std::map<std::string, efk::EffectEmitter*> _emitterMap;
	static EffectMng* s_instance;
};

