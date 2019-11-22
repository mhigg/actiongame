#pragma once
#include <cocos2d.h>
#include <memory>
#include <map>

#define lpAnimMng AnimationMng::GetInstance()

struct AnimData
{
	std::string spType;		// ｽﾌﾟﾗｲﾄの属性(player/enemy)
	std::string spName;		// ｽﾌﾟﾗｲﾄの名前
	std::string animName;	// ｱﾆﾒｰｼｮﾝの名前
	int frame;				// ｱﾆﾒｰｼｮﾝのﾌﾚｰﾑ数
	float delay;			// ｱﾆﾒｰｼｮﾝの1ﾌﾚｰﾑごとの間隔
	bool restore;			// ｱﾆﾒｰｼｮﾝが終了したとき最初のﾌﾚｰﾑに戻るかどうか
};

class AnimationMng
{
public:
	static AnimationMng& GetInstance(void)
	{
		if (s_instance == nullptr)
		{
			 s_instance = new AnimationMng();
		}
		return (*s_instance);
	}

	void AddAnimation(AnimData& animData);
	void SetAnimation(cocos2d::Sprite& sprite, const std::string& animKey);

private:
	AnimationMng();
	~AnimationMng();

	static AnimationMng* s_instance;
};

