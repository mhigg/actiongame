#pragma once
enum class INPUT_ID
{
	NON,	// 壗傕墴偟偰偄側偄忬懺
	LEFT,	// 嵍
	RIGHT,	// 塃
	UP,		// 忋
	DOWN,	// 壓
	BTN_1,	// 无垒1
	BTN_2,	// 无垒2
	BTN_3,	// 无垒3
	BTN_4,	// 无垒4
	MAX
};

INPUT_ID begin(INPUT_ID);
INPUT_ID end(INPUT_ID);
INPUT_ID operator*(INPUT_ID id);
INPUT_ID operator++(INPUT_ID& id);