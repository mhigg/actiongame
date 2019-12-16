#include "SoundMng.h"
#include <cocos2d.h>
#include "ck/ck.h"
#include "ck/config.h"

SoundMng* SoundMng::s_instance = nullptr;

#if CK_PLATFORM_ANDROID
#ifdef __cplusplus
extern "C" {
#endif
	JNIEXPORT void JNICALL Java_org_cocos2dx_cpp_AppActivity_initCricket(JNIEnv * env, jclass activity, jobject context)
	{
		CkConfig config(env, context);
		CkInit(&config);
		/*CkBank* g_bank = CkBank::newBank("dsptouch.ckb");
		CkSound* g_sound = CkSound::newBankSound(g_bank, "hiphoppiano");
		g_sound->setLoopCount(-1);
		g_sound->play();*/
	}
#ifdef __cplusplus
}
#endif
#endif

VecSound SoundMng::GetSound(const std::string& key)
{
	return GetSound(key, key, false);
}

VecSound SoundMng::GetSound(const std::string& key, const std::string& fileName, bool isBank)
{
	if (_bankMap.find(key) == _bankMap.end())
	{
		if (isBank)
		{
		#ifdef CK_PLATFORM_ANDROID
			_bankMap.emplace(key, CkBank::newBank(fileName.c_str()));
		#else
			_bankMap.emplace(key, CkBank::newBank(("Resources/" + fileName).c_str(), kCkPathType_ExeDir));
		#endif
			for (int idx = 0; idx < _bankMap[key]->getNumSounds(); idx++)
			{
				auto sound = _bankMap[key]->getSoundName(idx);
				_soundMap[key].emplace_back(CkSound::newBankSound(_bankMap[key], sound));
			}
		}
		else
		{
		#ifdef CK_PLATFORM_ANDROID
			_soundMap[key].emplace_back(CkSound::newStreamSound(fileName.c_str()));
		#else
			_soundMap[key].emplace_back(CkSound::newStreamSound(("Resources/" + fileName).c_str(), kCkPathType_ExeDir));
		#endif
		}
	}

	return _soundMap[key];
}

void SoundMng::Update(void)
{
	CkUpdate();
}

void SoundMng::Shutdown(void)
{
	CkShutdown();
}

void SoundMng::Suspend(void)
{
	CkSuspend();
}

void SoundMng::Resume(void)
{
	CkResume();
}

SoundMng::SoundMng()
{
#ifdef CK_PLATFORM_WIN
	CkConfig config;
	CkInit(&config);
#endif

	//auto schedule = cocos2d::Director::getInstance()->getScheduler();
	//schedule->schedule([](float f) {
	//	CkUpdate();
	//}, this, 0.016, CC_REPEAT_FOREVER, 0.0, false, "sounds");
}

SoundMng::~SoundMng()
{
	//for (auto& bank : _bankMap)
	//{
	//	bank.second->destroy();
	//}
	//for (auto& sound : _soundMap)
	//{
	//	sound.second->destroy();
	//}
}
