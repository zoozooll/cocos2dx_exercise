#include <stdio.h>
#include <iostream>

#include "HelloWorldScene.h"
#include "SpriteExercise.h"
#include "ActionExercise.h"
#include "WidgetsScene.h"
#include "PhysiceScene.h"
#include "ClockBackgroundScene.h"

using namespace std;
USING_NS_CC;
static const char* const FirstMenuLabel = "Replace To Next Scene";
static const char* const SPRITE_EXAMPLES = "Sprite Examples";
static const char* const ACTION_EXAMPLES = "Action Examples";
static const char* const WIDGETS_EXAMPLES = "Widgets Examples";
static const char* const PHYSICS_EXAMPLES = "Physics Examples";
static const char* const CLOCK_EXAMPLES = "Clock Examples";

static Scene* createScene2(const int index);

static function<Scene*()> createFunctions[] = {
	[](){ return SpriteExercise::createScene(); },
	[](){ return ActionExercise::createScene(); },
	[](){ return WidgetsScene::createScene(); },
	[](){ return PhysicsScene::createScene(); },
	[](){ return ClockBackgroundScene::createScene(); }
};
	


Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

	/*createFunctions.insert(SPRITE_EXAMPLES, [](){ return SpriteExercise::create(); });
	createFunctions.insert(ACTION_EXAMPLES, [](){ return ActionExercise::create(); });
	createFunctions.insert(WIDGETS_EXAMPLES, [](){ return WidgetsScene::create(); });
	createFunctions.insert(PHYSICS_EXAMPLES, [](){ return PhysicsScene::create(); });
	createFunctions.insert(CLOCK_EXAMPLES, [](){ return ClockBackgroundScene::create(); });*/
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...
	int index = 1;
	// Sprite MENU
	LabelTTF* itemlabel = LabelTTF::create(SPRITE_EXAMPLES, "Marker Felt.ttf", 32);
	MenuItemLabel* menuItem = MenuItemLabel::create(itemlabel);

	ccMenuCallback callBack = CC_CALLBACK_1(HelloWorld::menuClickedCallback, this);
	menuItem->setName(SPRITE_EXAMPLES);
	menuItem->setTag(1001);
	menuItem->setCallback(callBack);
	menuItem->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2).x,
		(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height).y - (++index) * 40));

	menu->addChild(menuItem, 2);

	// Action MENU
	itemlabel = LabelTTF::create(ACTION_EXAMPLES, "Marker Felt.ttf", 32);
	menuItem = MenuItemLabel::create(itemlabel);
	menuItem->setTag(1002);
	callBack = CC_CALLBACK_1(HelloWorld::menuClickedCallback, this);
	menuItem->setName(ACTION_EXAMPLES);
	menuItem->setCallback(callBack);
	menuItem->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2).x,
		(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height).y - (++index) * 40));

	menu->addChild(menuItem, 2);

	// WIDGETS MENU
	itemlabel = LabelTTF::create(WIDGETS_EXAMPLES, "Marker Felt.ttf", 32);
	menuItem = MenuItemLabel::create(itemlabel);
	menuItem->setTag(1003);
	callBack = CC_CALLBACK_1(HelloWorld::menuClickedCallback, this);
	menuItem->setName(WIDGETS_EXAMPLES);
	menuItem->setCallback(callBack);
	menuItem->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2).x,
		(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height).y - (++index) * 40));

	menu->addChild(menuItem, 2);

	// Physics system MENU
	itemlabel = LabelTTF::create(PHYSICS_EXAMPLES, "Marker Felt.ttf", 32);
	menuItem = MenuItemLabel::create(itemlabel);
	menuItem->setTag(1004);
	callBack = CC_CALLBACK_1(HelloWorld::menuClickedCallback, this);
	menuItem->setName(PHYSICS_EXAMPLES);
	menuItem->setCallback(callBack);
	menuItem->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2).x,
		(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height).y - (++index) * 40));

	menu->addChild(menuItem, 2);


	// Clock exercise MENU
	itemlabel = LabelTTF::create(CLOCK_EXAMPLES, "Marker Felt.ttf", 32);
	menuItem = MenuItemLabel::create(itemlabel);
	menuItem->setTag(1005);
	callBack = CC_CALLBACK_1(HelloWorld::menuClickedCallback, this);
	menuItem->setName(CLOCK_EXAMPLES);
	menuItem->setCallback(callBack);
	menuItem->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2).x,
		(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height).y - (++index) * 40));

	menu->addChild(menuItem, 2);

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}




void HelloWorld::menuClickedCallback(Ref* pSender)
{

	int tag = ((Node*)pSender)->getTag();
	Director::getInstance()->replaceScene(createScene2(tag - 1001));
    
};

static Scene* createScene2(const int index)
{
	function<Scene*()> getter = createFunctions[index];
	Scene* scene = getter();
	return scene;
}
