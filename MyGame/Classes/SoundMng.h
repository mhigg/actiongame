#pragma once
#include <map>
#include <vector>
#include <memory>
#include <jni.h>
#include "ck/bank.h"
#include "ck/sound.h"

#define lpSoundMng SoundMng::GetInstance()
#define SOUND(KEY) lpSoundMng.GetSound(KEY)						// KEY‚É‰‚¶‚½»³İÄŞ‚ğæ“¾
#define SET_SOUND(KEY, BANK) lpSoundMng.GetSound(KEY, BANK)		// BANK‚©‚ç»³İÄŞ‚ğ“Ç‚İ‚ñ‚Å•Û‘¶‚·‚é KEY‚ÅŒÄ‚Ño‚µ–¼‚ğ•t‚¯‚é

#ifndef __ANDROID_JNI__
#define __ANDROID_JNI__
#ifdef __cplusplus
extern "C" {
#endif

	JNIEXPORT void JNICALL Java_org_cocos2dx_cpp_AppActivity_initCricket(
		JNIEnv * env,
		jclass activity,
		jobject context
	);

#ifdef __cplusplus
}
#endif
#endif

using VecSound = std::vector<CkSound*>;

class SoundMng
{
public:
	static SoundMng& GetInstance(void)
	{
		if (s_instance == nullptr)
		{
			s_instance = new SoundMng();
		}
		return (*s_instance);
	}

	VecSound GetSound(const std::string& key);
	VecSound GetSound(const std::string& key, const std::string& bankName);

	void Update(void);
	void Shutdown(void);	// CkShutdown‚ğŒÄ‚Ño‚µµ°ÃŞ¨µ‚ğI—¹‚·‚é
	void Suspend(void);		// CkSuspend‚ğŒÄ‚Ño‚µ‰¹‚ğˆê’â~‚·‚é
	void Resume(void);		// CkResume‚ğŒÄ‚Ño‚µ‰¹‚ğÄŠJ‚·‚é
	
private:
	SoundMng();
	~SoundMng();

	std::map<std::string, CkBank*> _bankMap;	// ÊŞİ¸–¼‚²‚Æ‚ÉÊŞİ¸‚ğŠi”[‚·‚é
	std::map<std::string, VecSound> _soundMap;	// »³İÄŞ–¼‚²‚Æ‚É»³İÄŞ‚ğŠi”[‚·‚é
	static SoundMng* s_instance;
};
