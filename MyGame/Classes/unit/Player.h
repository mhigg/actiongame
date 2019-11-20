#pragma once
#include <cocos2d.h>
#include <action/ActionCtrl.h>
#include <input/OPRT_state.h>

class Player :
	public cocos2d::Sprite
{
public:
	static Player* createPlayer();

	Player();
	~Player();

	void update(float delta);			// �X�V����
	
	const STATE nowState(void) const;	// ���݂̱���ݏ�Ԃ��擾����
	void nowState(const STATE state);	// ���݂̱���ݏ�Ԃ�Ă���
	const DIR dir(void) const;			// �������擾����
	void dir(const DIR direction);		// ������Ă���
	const uniqueOPRT& inputState(void);	// ���͏����擾����

	// implement the "static create()" method manually
	CREATE_FUNC(Player);

private:
	void InitAction(void);		// ����݂̏����o�^

	std::string _nowActName;	// ����ݏ�Ԗ�
	STATE _nowState;			// ���݂̱���ݏ��
	DIR _dir;					// ����

	uniqueOPRT _inputState;		// ���͏��擾�ϐ�
	ActionCtrl* _actCtrl;		// ����ݐ���p�׽�ϐ�
};

