#pragma once
enum class INPUT_ID
{
	NON,	// 何も押していない状態
	LEFT,	// 左
	RIGHT,	// 右
	UP,		// 上
	DOWN,	// 下
	BTN_1,	// ﾎﾞﾀﾝ1
	BTN_2,	// ﾎﾞﾀﾝ2
	BTN_3,	// ﾎﾞﾀﾝ3
	BTN_4,	// ﾎﾞﾀﾝ4
	MAX
};

INPUT_ID begin(INPUT_ID);
INPUT_ID end(INPUT_ID);
INPUT_ID operator*(INPUT_ID id);
INPUT_ID operator++(INPUT_ID& id);