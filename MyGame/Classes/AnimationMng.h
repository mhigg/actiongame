#pragma once
#include <cocos2d.h>
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

	// 新しいｱﾆﾒｰｼｮﾝを追加する
	void AddAnimation(AnimData& animData);

	// 指定したｱﾆﾒｰｼｮﾝをｾｯﾄする
	void SetAnimation(cocos2d::Sprite& sprite, const std::string& spriteName, const std::string& animName);

private:
	AnimationMng();
	~AnimationMng();

	static AnimationMng* s_instance;
};

