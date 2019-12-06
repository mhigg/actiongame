#pragma once
#include <map>
#include <vector>
#include <memory>
#include <jni.h>
#include "ck/bank.h"
#include "ck/sound.h"

#define lpSoundMng SoundMng::GetInstance()
#define SOUND(KEY) lpSoundMng.GetSound(KEY)						// KEY�ɉ���������ނ��擾
#define SET_SOUND(KEY, BANK) lpSoundMng.GetSound(KEY, BANK)		// BANK���绳��ނ�ǂݍ���ŕۑ����� KEY�ŌĂяo������t����

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
	void Shutdown(void);	// CkShutdown���Ăяo�����ި����I������
	void Suspend(void);		// CkSuspend���Ăяo�������ꎞ��~����
	void Resume(void);		// CkResume���Ăяo�������ĊJ����
	
private:
	SoundMng();
	~SoundMng();

	std::map<std::string, CkBank*> _bankMap;	// ��ݸ�����Ƃ���ݸ���i�[����
	std::map<std::string, VecSound> _soundMap;	// ����ޖ����Ƃɻ���ނ��i�[����
	static SoundMng* s_instance;
};
