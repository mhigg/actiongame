#pragma once
#include <map>
#include <vector>
#include <memory>
#include "ck/bank.h"
#include "ck/sound.h"

#define lpSoundMng SoundMng::GetInstance()
#define SOUND(KEY) lpSoundMng.GetSound(KEY)						// KEY‚É‰‚¶‚½»³İÄŞ‚ğæ“¾
#define SET_SOUND(KEY, BANK) lpSoundMng.GetSound(KEY, BANK)		// BANK‚©‚ç»³İÄŞ‚ğ“Ç‚İ‚ñ‚Å•Û‘¶‚·‚é KEY‚ÅŒÄ‚Ño‚µ–¼‚ğ•t‚¯‚é

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

	std::map<std::string, CkBank*> _bankMap;	// ÊŞİ¸–¼‚²‚Æ‚ÉÊŞİ¸‚ğŠi”[‚·‚é
	std::map<std::string, VecBank> _soundMap;	// »³İÄŞ–¼‚²‚Æ‚É»³İÄŞ‚ğŠi”[‚·‚é
	static std::unique_ptr<SoundMng, SoundMngDeleter> s_instance;
};

