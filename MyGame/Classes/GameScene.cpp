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

#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include <unit/Player.h>
#include <unit/Enemy.h>
#include <EffectMng.h>
#include <SoundMng.h>

USING_NS_CC;

Scene* GameScene::createScene()
{
    return GameScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(GameScene::menuCloseCallback, this));

    if (closeItem == nullptr
	 || closeItem->getContentSize().width <= 0
	 || closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "We are Japanese People"
    // create and initialize a label

    auto label = Label::createWithTTF("We are Japanese People", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
	else
	{
		// position the label on the center of the screen
		label->setPosition(Vec2(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height - label->getContentSize().height));

		// add the label as a child to this layer
		this->addChild(label, 1);
	}

	LayerSetUp();
	EffectSetUp();
	SoundSetUp();

//	SOUND("piano")[1]->play();

	this->scheduleUpdate();
    return true;
}

void GameScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}

void GameScene::update(float delta)
{
	_effectMng->update();
}

bool GameScene::LayerSetUp(void)
{
	// backImageLayer
	auto backLayer = Layer::create();
	backLayer->setName("backLayer");

	auto backImgBefor = Sprite::create("image/Environment/background.png");
	backImgBefor->setAnchorPoint(Vec2::ZERO);
	backImgBefor->setPosition(Vec2::ZERO);

	auto backImgAfter = Sprite::create("image/Environment/background.png");
	backImgAfter->setAnchorPoint(Vec2::ZERO);
	backImgAfter->setPosition(Vec2::ZERO + Vec2(720, 0));

	backLayer->addChild(backImgBefor);
	backLayer->addChild(backImgAfter);
	this->addChild(backLayer, static_cast<int>(LAYER::BACK));

	// middleImageLayer
	auto middleLayer = Layer::create();
	middleLayer->setName("frontLayer");

	auto middleImgBefor = Sprite::create("image/Environment/middleground.png");
	middleImgBefor->setAnchorPoint(Vec2::ZERO);
	middleImgBefor->setPosition(Vec2::ZERO);

	auto middleImgAfter = Sprite::create("image/Environment/middleground.png");
	middleImgAfter->setAnchorPoint(Vec2::ZERO);
	middleImgAfter->setPosition(Vec2::ZERO + Vec2(816, 0));

	middleLayer->addChild(middleImgBefor);
	middleLayer->addChild(middleImgAfter);
	this->addChild(middleLayer, static_cast<int>(LAYER::MIDDLE));

	// groundLayer
	auto groundLayer = Layer::create();
	groundLayer->setName("groundLayer");

	// map
	auto stageMap = TMXTiledMap::create("maps/fourthmap.tmx");
	if (stageMap == nullptr)
	{
		// load failed
		problemLoading("'fourthmap.tmx'");
	}
	else
	{
		// load successed
		//auto frontBlock = stageMap->getLayer("front_objects");
		//frontBlock->setGlobalZOrder(static_cast<int>(LAYER::GROUND_MIDDLE));
		////auto isGround = stageMap->getLayer("isground");
		////isGround->setGlobalZOrder(static_cast<int>(LAYER::GROUND_MIDDLE));
		//auto wall = stageMap->getLayer("walls");
		//wall->setGlobalZOrder(static_cast<int>(LAYER::GROUND_FRONT));
		stageMap->setAnchorPoint(Vec2::ZERO);
		stageMap->setPosition(Vec2::ZERO);
		stageMap->setName("mapData");
	}

	groundLayer->addChild(stageMap);
	this->addChild(groundLayer, static_cast<int>(LAYER::GROUND));

#ifdef _DEBUG
	// debugLayer
	auto debugLayer = Layer::create();
	debugLayer->setName("debugLayer");

	auto mapSize = stageMap->getMapSize();
	auto tileSize = stageMap->getTileSize();

	auto drawPen = DrawNode::create();
	for (int x = 0; x < (int)mapSize.width; x++)
	{
		drawPen->drawSegment(
			Vec2(x * tileSize.width, 0),
			Vec2(x * tileSize.width, mapSize.height * tileSize.height),
			1.0f,
			Color4F::WHITE);
	}
	for (int y = 0; y < (int)mapSize.height; y++)
	{
		drawPen->drawSegment(
			Vec2(0, y * tileSize.height),
			Vec2(mapSize.width * tileSize.width, y * tileSize.height),
			1.0f,
			Color4F::WHITE);
	}

	debugLayer->addChild(drawPen);
	this->addChild(debugLayer, 0);
#else
	auto debugLayer = Layer::create();
	debugLayer->setName("debugLayer");
#endif // _DEBUG

	// mainLayer
	auto mainLayer = Layer::create();
	mainLayer->setName("mainLayer");

	cocos2d::Sprite* player = Player::createPlayer();
	if (player == nullptr)
	{
		// load failed
		problemLoading("'player-idle-1.png'");
	}
	else
	{
		// load successed
		// position the sprite on the center of the screen
		player->setPosition(Vec2(200,350));
	}
	mainLayer->addChild(player);
	this->addChild(mainLayer, static_cast<int>(LAYER::MAIN));

	auto effectLayer = Layer::create();
	effectLayer->setName("effectLayer");

	return true;
}

bool GameScene::EffectSetUp(void)
{
	auto director = Director::getInstance();
	//_effectMng.reset(efk::EffectManager::create(Director::getInstance()->getVisibleSize()));
	_effectMng = efk::EffectManager::create(director->getVisibleSize());

	auto effect = efk::Effect::create("Laser01.efk", 13.0f);
	if (effect != nullptr)
	{
		auto emitter = efk::EffectEmitter::create(_effectMng);
		emitter->setEffect(effect);
		emitter->setPlayOnEnter(true);

		emitter->setRotation3D(cocos2d::Vec3(0, 90, 0));
		emitter->setPosition(Vec2(320, 150));

		// emitter->setScale(13);
		this->addChild(emitter, 0);

		// No need (because it uses autorelease after 1.41)
		//effect->release();
	}

	return true;
}

bool GameScene::SoundSetUp(void)
{
	//SET_SOUND("piano", "dsptouch.ckb");
	//SOUND("piano")[1]->setLoopCount(-1);

	return true;
}

void GameScene::visit(cocos2d::Renderer * renderer, const cocos2d::Mat4 & parentTransform, uint32_t parentFlags)
{
	_effectMng->begin(renderer, _globalZOrder);
	cocos2d::Scene::visit(renderer, parentTransform, parentFlags);
	_effectMng->end(renderer, _globalZOrder);
}