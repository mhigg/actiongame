/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include <cocos2d.h>
#include <Effekseer/Effekseer.h>
#include <input/OPRT_state.h>

#pragma execution_character_set("utf-8")

enum class LAYER
{
	BACK		  = -100,	// backImageLayer
	MIDDLE		  = - 50,	// middleImageLayer
	GROUND		  = - 20,	// mainBlocksLayer
	MAIN		  =    0,	// player and enemy
	GROUND_BACK	  =   30,	// backBlocksLayer
	GROUND_MIDDLE =   50,	// middleBlocksLayer
	GROUND_FRONT  =  100,	// frontBlocksLayer
	MAX
};

class GameScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	void update(float delta);

	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);

private:
	bool LayerSetUp(void);		// ﾏｯﾌﾟﾚｲﾔｰのｾｯﾄｱｯﾌﾟ
	bool EffectSetUp(void);		// ｴﾌｪｸﾄ管理のｾｯﾄｱｯﾌﾟ
	bool SoundSetUp(void);		// ｻｳﾝﾄﾞのｾｯﾄｱｯﾌﾟ

	// ｹﾞｰﾑｼｰﾝ内の描画処理(Sceneｸﾗｽよりｵｰﾊﾞｰﾛｰﾄﾞ, ｴﾌｪｸﾄ再生に必要)
	virtual void visit(cocos2d::Renderer *renderer, const cocos2d::Mat4& parentTransform, uint32_t parentFlags) override;

	efk::EffectManager* _effectMng;
};

#endif // __GAME_SCENE_H__
