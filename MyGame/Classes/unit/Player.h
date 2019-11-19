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

	void update(float delta);			// XVˆ—
	
	const State nowState(void) const;	// Œ»İ‚Ì±¸¼®İó‘Ô‚ğæ“¾‚·‚é
	void nowState(const State state);	// Œ»İ‚Ì±¸¼®İó‘Ô‚ğ¾¯Ä‚·‚é
	const DIR dir(void) const;			// Œü‚«‚ğæ“¾‚·‚é
	void dir(const DIR direction);		// Œü‚«‚ğ¾¯Ä‚·‚é
	const uniqueOPRT& inputState(void);	// “ü—Íî•ñ‚ğæ“¾‚·‚é

	// implement the "static create()" method manually
	CREATE_FUNC(Player);

private:
	void InitAction(void);	// ±¸¼®İ‚Ì‰Šú“o˜^

	std::string _nowAction;	// ±¸¼®İó‘Ô–¼
	State _nowState;		// Œ»İ‚Ì±¸¼®İó‘Ô
	DIR _dir;				// Œü‚«

	uniqueOPRT _inputState;	// “ü—Íî•ñæ“¾•Ï”
	ActionCtrl* _actCtrl;	// ±¸¼®İ§Œä—p¸×½•Ï”
};

