#pragma once
enum class INPUT_ID
{
	NON,	// ���������Ă��Ȃ����
	LEFT,	// ��
	RIGHT,	// �E
	UP,		// ��
	DOWN,	// ��
	BTN_1,	// ����1
	BTN_2,	// ����2
	BTN_3,	// ����3
	BTN_4,	// ����4
	MAX
};

INPUT_ID begin(INPUT_ID);
INPUT_ID end(INPUT_ID);
INPUT_ID operator*(INPUT_ID id);
INPUT_ID operator++(INPUT_ID& id);