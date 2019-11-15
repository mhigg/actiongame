#pragma once
#include <cocos2d.h>
#include <action/ActionCtrl.h>
#include <input/OPRT_state.h>

//USING_NS_CC;

class Player;

class Player :
	public Sprite
{
public:
	static Player* createPlayer();

	Player();
	~Player();

	void update(float delta);

	const State nowState(void) const;
	
	// implement the "static create()" method manually
	CREATE_FUNC(Player);

private:
	void (Player::*updater)(void);

	void InitAction(void);

	void UpdateIdle(void);	// ��~���
	void UpdateMove(void);	// �ړ����
	void UpdateJump(void);	// �ެ��ߏ��

	void CheckGID(void);	// ���݂̍��W��GID�̌���

	State _nowState;			// ���݂̱���ݏ��
	bool gravity;			// true:�d�͂��� false:�d�͂Ȃ�
	bool jumpFlag;			// true:�ެ��ߒ� false:��ެ���
	Action* jumpAct = nullptr;
	std::vector<bool> collision;

	float speed;			// �ړ����x
	std::array<Vec2, static_cast<int>(DIR::MAX)> moveSpeed;

	uniqueOPRT _inputState;		// ���͏��擾�ϐ�
	ActionCtrl* _actCtrl;		// ����ݐ���p�׽�ϐ�
};

