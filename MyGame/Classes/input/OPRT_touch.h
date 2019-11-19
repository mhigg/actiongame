#pragma once
#include "OPRT_state.h"

struct OPRT_touch :
	public OPRT_state
{
	void Init(cocos2d::Node* sp)override;		// 入力判定処理ﾒｿｯﾄﾞの初期登録
	void Update(void)override;					// 入力情報の更新処理
	const OPRT_TYPE GetType(void)override;		// 入力装置のﾀｲﾌﾟを取得

private:
	cocos2d::Point start;
};

