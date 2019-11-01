#pragma once
#include "cocos2d.h"
#include <input/OPRT_state.h>

//USING_NS_CC;

enum class STATE
{
	IDLE,	// ��~���
	MOVE,	// �ړ����
	JUMP,	// �ެ��ߏ��
	MAX
};

class Player;

class Player :
	public Sprite
{
public:
	static Player* createPlayer();

	Player();
	~Player();

	void update(float delta);

	// implement the "static create()" method manually
	CREATE_FUNC(Player);

private:
	void (Player::*updater)(void);

	void UpdateIdle(void);	// ��~���
	void UpdateMove(void);	// �ړ����
	void UpdateJump(void);	// �ެ��ߏ��



	void CheckGID(void);	// ���݂̍��W��GID�̌���

	DIR dir;				// ����
	STATE nowState;			// ���݂̏��
	bool gravity;			// true:�d�͂��� false:�d�͂Ȃ�
	bool jumpFlag;			// true:�ެ��ߒ� false:��ެ���
	Action* jumpAct = nullptr;
	std::vector<bool> collision;

	float speed;			// �ړ����x
	std::array<Vec2, static_cast<int>(DIR::MAX)> moveSpeed;

	uniqueOPRT input;		// ���͏��擾�ϐ�
};

