#pragma once
#include <map>
#include <vector>
#include <memory>
#include <jni.h>
#include "ck/bank.h"
#include "ck/sound.h"

#define lpSoundMng SoundMng::GetInstance()
#define SOUND(KEY) lpSoundMng.GetSound(KEY)						// KEYに応じたｻｳﾝﾄﾞを取得
#define SET_SOUND(KEY, BANK) lpSoundMng.GetSound(KEY, BANK)		// BANKからｻｳﾝﾄﾞを読み込んで保存する KEYで呼び出し名を付ける

#ifndef __ANDROID_JNI__
#define __ANDROID_JNI__
#ifdef __cplusplus
extern "C" {
#endif
	// Android用のCricketの初期化処理
	JNIEXPORT void JNICALL Java_org_cocos2dx_cpp_AppActivity_initCricket(
		JNIEnv * env,
		jclass activity,
		jobject context
	);

#ifdef __cplusplus
}
#endif
#endif

using VecSound = std::vector<CkSound*>;	// CkSoundを格納するvector型

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

	// 指定したkeyのｻｳﾝﾄﾞを取得する。無ければ新たにｻｳﾝﾄﾞﾃﾞｰﾀを作成する
	VecSound GetSound(const std::string& key);

	// 指定したbankNameのｻｳﾝﾄﾞを取得し次回以降呼び出しやすいようにkeyを設定する。無ければ新たにｻｳﾝﾄﾞﾃﾞｰﾀを作成する
	VecSound GetSound(const std::string& key, const std::string& bankName);

	void Update(void);		// CkUpdate 毎ﾌﾚｰﾑ呼び出す
	void Shutdown(void);	// CkShutdownを呼び出しｵｰﾃﾞｨｵを終了する
	void Suspend(void);		// CkSuspendを呼び出し音を一時停止する
	void Resume(void);		// CkResumeを呼び出し音を再開する
	
private:
	SoundMng();
	~SoundMng();

	std::map<std::string, CkBank*> _bankMap;	// ﾊﾞﾝｸ名ごとにﾊﾞﾝｸを格納する
	std::map<std::string, VecSound> _soundMap;	// ｻｳﾝﾄﾞ名ごとにｻｳﾝﾄﾞを格納する
	static SoundMng* s_instance;
};
