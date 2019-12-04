#pragma once
/*#include <map>
#include <vector>
#include <memory>
#include "ck/bank.h"
#include "ck/sound.h"

#define lpSoundMng SoundMng::GetInstance()
#define SOUND(KEY) lpSoundMng.GetSound(KEY)						// KEYに応じたｻｳﾝﾄﾞを取得
#define SET_SOUND(KEY, BANK) lpSoundMng.GetSound(KEY, BANK)		// BANKからｻｳﾝﾄﾞを読み込んで保存する KEYで呼び出し名を付ける

using VecBank = std::vector<CkSound*>;

class SoundMng
{
public:
	static SoundMng& GetInstance(void)
	{
		return (*s_instance);
	}

	VecBank GetSound(const std::string& key);
	VecBank GetSound(const std::string& key, const std::string& bankName);

private:
	struct SoundMngDeleter
	{
		void operator()(SoundMng* soundMng) const
		{
			delete soundMng;
		}
	};
	SoundMng();
	~SoundMng();

	std::map<std::string, CkBank*> _bankMap;	// ﾊﾞﾝｸ名ごとにﾊﾞﾝｸを格納する
	std::map<std::string, VecBank> _soundMap;	// ｻｳﾝﾄﾞ名ごとにｻｳﾝﾄﾞを格納する
	static std::unique_ptr<SoundMng, SoundMngDeleter> s_instance;
};

*/