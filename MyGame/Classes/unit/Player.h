#pragma once
#include <cocos2d.h>
#include <action/ActionCtrl.h>
#include <input/OPRT_state.h>

class Player;

class Player :
	public cocos2d::Sprite
{
public:
	static Player* createPlayer();

	Player();
	~Player();

	void update(float delta);

	const State nowState(void) const;	// ���݂̱���ݏ�Ԃ��擾����
	void nowState(const State state);	// ���݂̱���ݏ�Ԃ�Ă���
	const DIR dir(void) const;			// �������擾����
	void dir(const DIR direction);		// ������Ă���

	// implement the "static create()" method manually
	CREATE_FUNC(Player);

private:
	void (Player::*updater)(void);

	void InitAction(void);

	void UpdateIdle(void);	// ��~���
	void UpdateMove(void);	// �ړ����
	void UpdateJump(void);	// �ެ��ߏ��

	State _nowState;		// ���݂̱���ݏ��
	DIR _dir;				// ����
	bool gravity;			// true:�d�͂��� false:�d�͂Ȃ�
	bool jumpFlag;			// true:�ެ��ߒ� false:��ެ���
	cocos2d::Action* jumpAct = nullptr;
	std::vector<bool> collision;

	float speed;			// �ړ����x
	std::array<cocos2d::Vec2, static_cast<int>(DIR::MAX)> moveSpeed;

	uniqueOPRT _inputState;	// ���͏��擾�ϐ�
	ActionCtrl* _actCtrl;	// ����ݐ���p�׽�ϐ�
};

