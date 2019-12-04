#pragma once
#include <cocos2d.h>
#include <action/ActionCtrl.h>
#include <input/OPRT_state.h>

class Enemy :
	public cocos2d::Sprite
{
public:
	static Enemy* createEnemy();

	Enemy();
	~Enemy();

	void update(float delta);

	// implement the "static create()" method manually
	CREATE_FUNC(Enemy);

private:
	void InitAction(void);		// ����݂̏����o�^
	void InitAnimation(void);	// ��Ұ��݂̏����o�^

	std::string _nowActName;	// ����ݏ�Ԗ�
	STATE _nowState;			// ���݂̱���ݏ��
	DIR _dir;					// ����

	uniqueOPRT _inputState;		// ���͏��擾�ϐ�
	ActionCtrl* _actCtrl;		// ����ݐ���p�׽�ϐ�
};

