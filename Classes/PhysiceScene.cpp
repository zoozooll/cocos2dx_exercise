#include "PhysiceScene.h"
#include "PhysicsDemo.h"

#define CL(__className__) [](){ return __className__::create();}
#define MAX_LAYER (sizeof(createFunctions) / sizeof(createFunctions[0]))

static int sceneIdx = -1;

static std::function<PhysicsDemo*()> createFunctions[] = {
	CL(PhysicsCorrelationToSprite),
	CL(PhysicsCollisionFiltering),
	CL(PhysicsCollisionProcessing),
	CL(PhysicsRayTest),
	CL(PhysicsJointsDistance)
};

PhysicsScene::PhysicsScene()
{
	
}


PhysicsScene::~PhysicsScene()
{
}

Scene* PhysicsScene::createScene()
{

	sceneIdx = -1;
	// 'scene' is an autorelease object
	Scene* scene = Scene::createWithPhysics();

	// 'layer' is an autorelease object
	PhysicsScene* layer = PhysicsScene::create();
	layer->setName("rootLayer");
	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;

}

bool PhysicsScene::init()
{
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	MenuItemImage* closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(PhysicsScene::onMenuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	MenuItemImage* backItem = MenuItemImage::create("leftNormal.png", "leftSelected.png",
		CC_CALLBACK_1(PhysicsScene::back, this)
		);

	MenuItemImage* restartItem = MenuItemImage::create("restartNormal.png", "restartSelected.png",
		CC_CALLBACK_1(PhysicsScene::restart, this)
		);

	MenuItemImage* nextItem = MenuItemImage::create("rightNormal.png", "rightSelected.png",
		CC_CALLBACK_1(PhysicsScene::next, this)
		);
	Vec2 s_center = origin + visibleSize / 2;
	Size restartItemSize = restartItem->getContentSize();
	backItem->setPosition(s_center.x - restartItemSize.width * 2, origin.y + restartItemSize.height / 2);
	restartItem->setPosition(s_center.x, origin.y + restartItemSize.height / 2);
	nextItem->setPosition(s_center.x + restartItemSize.width * 2, origin.y + restartItemSize.height / 2);
	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem,  backItem, restartItem, nextItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 5);

	next(nullptr);
}

void PhysicsScene::onMenuCloseCallback(Ref* sender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void PhysicsScene::next(Ref* ref)
{
	sceneIdx++;
	if (sceneIdx >= MAX_LAYER)
	{
		sceneIdx = 0;
	}

	if (getChildByTag(sceneIdx) != nullptr)
	{
		removeChildByTag(sceneIdx);
	}
	PhysicsDemo* layer = (createFunctions[sceneIdx])();
	addChild(layer, 1);
	/*layer->setBackCallback(PhysicsScene::back);
	layer->setRestartCallback(PhysicsScene::restart);
	layer->setNextCallback(PhysicsScene::next);*/
	
}

void PhysicsScene::back(Ref* ref)
{
	sceneIdx--;
	if (sceneIdx < 0)
	{
		sceneIdx = MAX_LAYER;
	}
	if (getChildByTag(sceneIdx) != nullptr)
	{
		removeChildByTag(sceneIdx);
	}
	PhysicsDemo* layer = (createFunctions[sceneIdx])();
	addChild(layer, 1);
	/*layer->setBackCallback(PhysicsScene::back);
	layer->setRestartCallback(PhysicsScene::restart);
	layer->setNextCallback(PhysicsScene::next);*/
}

void PhysicsScene::restart(Ref* ref)
{
	if (getChildByTag(sceneIdx) != nullptr)
	{
		removeChildByTag(sceneIdx);
	}
	PhysicsDemo* layer = (createFunctions[sceneIdx])();
	addChild(layer, 1);
	/*layer->setBackCallback(PhysicsScene::back);
	layer->setRestartCallback(PhysicsScene::restart);
	layer->setNextCallback(PhysicsScene::next);*/
	
}
