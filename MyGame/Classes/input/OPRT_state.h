#pragma once
#include <array>
#include <cocos2d.h>
#include "INPUT_ID.h"

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
	INPUT,	// 入力された生の入力情報
	MAX
};

#define nowTrg static_cast<int>(TRG::NOW)
#define oldTrg static_cast<int>(TRG::OLD)
#define inputTrg static_cast<int>(TRG::INPUT)

struct OPRT_state;

using TrgAry = std::array<bool, static_cast<int>(TRG::MAX)>;
using InputAry = std::array<TrgAry, static_cast<int>(INPUT_ID::MAX)>;
using uniqueOPRT = std::unique_ptr<OPRT_state>;

struct OPRT_state
	: public cocos2d::Ref
{
	OPRT_state(void);
	virtual void Init(cocos2d::Node* sp) = 0;	// 入力判定処理ﾒｿｯﾄﾞの初期登録
	virtual void Update(void);					// 入力情報の更新処理
	const InputAry& GetInputAry(void);			// 現在の入力情報を取得
	virtual const OPRT_TYPE GetType(void) = 0;	// 入力装置のﾀｲﾌﾟを取得

protected:
	InputAry _pressFlags;	// 現在の入力ﾌﾗｸﾞを格納
};
