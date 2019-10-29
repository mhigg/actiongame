#pragma once
#include <array>
#include "cocos2d.h"
#include "2d/CCNode.h"
#include "DIR.h"

USING_NS_CC;

enum class OPRT_TYPE
{
	KEY,	// ｷｰﾎﾞｰﾄﾞ入力
	TOUCH,	// ﾀｯﾁﾊﾟﾈﾙ入力
	MAX
};

enum class TRG
{
	NOW,	// 現在の入力情報
	OLD,	// 1ﾌﾚｰﾑ前の入力情報
	MAX
};

class OPRT_state;

using NowOld = std::pair<bool, bool>;
using InputAry = std::array<NowOld, static_cast<int>(DIR::MAX)>;
using uniqueOPRT = std::unique_ptr<OPRT_state>;

struct OPRT_state
{
	OPRT_state(void)
	{
		pressFlags = {
			NowOld{false,false},
			NowOld{false,false},
			NowOld{false,false},
			NowOld{false,false},
			NowOld{false,false}
		};
	};
	virtual void Init(Node* sp) = 0;			// 入力判定処理ﾒｿｯﾄﾞの初期登録
	virtual void UpDate(void) = 0;				// 入力情報の更新処理
	virtual const OPRT_TYPE GetType(void) = 0;	// 入力装置のﾀｲﾌﾟを取得
	const InputAry & GetInputAry(void)			// 現在の入力情報を取得
	{
		return pressFlags;
	}

protected:
	InputAry pressFlags;	// 現在の入力ﾌﾗｸﾞを格納
};
