#include "SoundMng.h"

/*std::unique_ptr<SoundMng, SoundMng::SoundMngDeleter> SoundMng::s_instance(new SoundMng());

VecBank SoundMng::GetSound(const std::string& key)
{
	return GetSound(key, key);
}

VecBank SoundMng::GetSound(const std::string& key, const std::string& bankName)
{
	if (_bankMap.find(key) == _bankMap.end())
	{
		_bankMap.emplace(key, CkBank::newBank(bankName.c_str(), kCkPathType_FileSystem));
		for (int idx = 0; idx < _bankMap[key]->getNumSounds(); idx++)
		{
			auto sound = _bankMap[key]->getSoundName(idx);
			_soundMap[key].emplace_back(CkSound::newBankSound(_bankMap[key], sound));
		}
	}

	return _soundMap[key];
}

SoundMng::SoundMng()
{
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
*/