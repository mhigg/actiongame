#pragma once
#include <map>
#include <vector>
#include <memory>
#include "ck/bank.h"
#include "ck/sound.h"

#define lpSoundMng SoundMng::GetInstance()
#define SOUND(KEY) lpSoundMng.GetSound(KEY)						// KEY�ɉ���������ނ��擾
#define SET_SOUND(KEY, BANK) lpSoundMng.GetSound(KEY, BANK)		// BANK���绳��ނ�ǂݍ���ŕۑ����� KEY�ŌĂяo������t����

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

	std::map<std::string, CkBank*> _bankMap;	// ��ݸ�����Ƃ���ݸ���i�[����
	std::map<std::string, VecBank> _soundMap;	// ����ޖ����Ƃɻ���ނ��i�[����
	static std::unique_ptr<SoundMng, SoundMngDeleter> s_instance;
};

