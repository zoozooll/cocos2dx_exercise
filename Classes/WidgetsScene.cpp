#include "WidgetsScene.h"
#include "WidgetLabelLayer.h"
#include "WidgetMenuLayer.h"
#include "WidgetButtonLayer.h"
#include "WidgetCheckboxLayer.h"
#include "WidgetLoadingbarLayer.h"
#include "WidgetSliderLayer.h"
#include "WidgetTextfieldLayer.h"
#include "WidgetTilemapLayer.h"
#include "WidgetParticleLayer.h"
#include "WidgetParallaxLayer.h"

USING_NS_CC;

static void playingWidgetsLayerLable();
static void playingWidgetsLayerMenu();
static void playingWidgetsLayerButton();
static void playingWidgetsLayerCheckbox();
static void playingWidgetsLayerLoadingBar();
static void playingWidgetsLayerSlider();
static void playingWidgetsLayerTextField();
static void playingWidgetsLayerTilemap();
static void playingWidgetsLayerParticle();
static void playingWidgetsLayerParallax();


WidgetsScene::WidgetsScene()
{
}


WidgetsScene::~WidgetsScene()
{
}

Scene* WidgetsScene::createScene()
{
	// 'scene' is an autorelease object
	Scene* scene = Scene::create();

	// 'layer' is an autorelease object
	Layer* layer = WidgetsScene::create();
	layer->setName("rootLayer");
	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;

}


bool WidgetsScene::init()
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
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(WidgetsScene::onMenuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	LabelTTF* label = LabelTTF::create("Widgets Scene Exercise", "Marker Felt.ttf", 32);
	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));
	this->addChild(label, 1);

	int index = 2;
	// Label
	LabelTTF* itemlabel = LabelTTF::create("Label", "Marker Felt.ttf", 32);
	MenuItemLabel* menuItem = MenuItemLabel::create(itemlabel);
	
	ccMenuCallback callBack = CC_CALLBACK_1(WidgetsScene::menuClickedCallback, this);
	menuItem->setName("Label");
	menuItem->setCallback(callBack);
	menuItem->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2).x,
		(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height).y - (++index) * 40));

	menu->addChild(menuItem, 2);

	// Menu and menu item
	itemlabel = LabelTTF::create("Menu", "Marker Felt.ttf", 32);
	menuItem = MenuItemLabel::create(itemlabel);
	menuItem->setName("Menu");
	menuItem->setCallback(callBack);
	menuItem->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2).x,
		(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height).y - (++index) * 40));

	menu->addChild(menuItem, 2);
	
	// Button
	itemlabel = LabelTTF::create("Button", "Marker Felt.ttf", 32);
	menuItem = MenuItemLabel::create(itemlabel);
	menuItem->setName("Button");
	menuItem->setCallback(callBack);
	menuItem->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2).x,
		(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height).y - (++index) * 40));
	menu->addChild(menuItem, 2);

	// Checkbox
	itemlabel = LabelTTF::create("Checkbox", "Marker Felt.ttf", 32);
	menuItem = MenuItemLabel::create(itemlabel);
	menuItem->setName("Checkbox");
	menuItem->setCallback(callBack);
	menuItem->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2).x,
		(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height).y - (++index) * 40));

	menu->addChild(menuItem, 2);

	// LoadingBar
	itemlabel = LabelTTF::create("LoadingBar", "Marker Felt.ttf", 32);
	menuItem = MenuItemLabel::create(itemlabel);
	menuItem->setName("LoadingBar");
	menuItem->setCallback(callBack);
	menuItem->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2).x,
		(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height).y - (++index) * 40));

	menu->addChild(menuItem, 2);

	// Slider
	itemlabel = LabelTTF::create("Slider", "Marker Felt.ttf", 32);
	menuItem = MenuItemLabel::create(itemlabel);
	menuItem->setName("Slider");
	menuItem->setCallback(callBack);
	menuItem->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2).x,
		(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height).y - (++index) * 40));

	menu->addChild(menuItem, 2);

	// TextField
	itemlabel = LabelTTF::create("TextField", "Marker Felt.ttf", 32);
	menuItem = MenuItemLabel::create(itemlabel);
	menuItem->setName("TextField");
	menuItem->setCallback(callBack);
	menuItem->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2).x,
		(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height).y - (++index) * 40));

	menu->addChild(menuItem, 2);

	// Timemap
	itemlabel = LabelTTF::create("Timemap", "Marker Felt.ttf", 32);
	menuItem = MenuItemLabel::create(itemlabel);
	menuItem->setName("Timemap");
	menuItem->setCallback(callBack);
	menuItem->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2).x,
		(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height).y - (++index) * 40));

	menu->addChild(menuItem, 2);

	// Particle
	itemlabel = LabelTTF::create("Particle", "Marker Felt.ttf", 32);
	menuItem = MenuItemLabel::create(itemlabel);
	menuItem->setName("Particle");
	menuItem->setCallback(callBack);
	menuItem->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2).x,
		(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height).y - (++index) * 40));

	menu->addChild(menuItem, 2);

	// Parallax
	itemlabel = LabelTTF::create("Parallax", "Marker Felt.ttf", 32);
	menuItem = MenuItemLabel::create(itemlabel);
	menuItem->setName("Parallax");
	menuItem->setCallback(callBack);
	menuItem->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2).x,
		(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height).y - (++index) * 40));

	menu->addChild(menuItem, 2);
	return true;
}

void WidgetsScene::onMenuCloseCallback(Ref* sender)
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

void WidgetsScene::menuClickedCallback(Ref* sender)
{
	this->setVisible(false);
	std::string tag = ((Node*)sender)->getName();
	if (tag == "Label")
	{
		playingWidgetsLayerLable();
	}
	else if (tag == "Menu")
	{
		playingWidgetsLayerMenu();
	}
	else if (tag == "Button")
	{
		playingWidgetsLayerButton();
	}
	else if (tag == "Checkbox")
	{
		playingWidgetsLayerCheckbox();
	}
	else if (tag == "LoadingBar")
	{
		playingWidgetsLayerLoadingBar();
	}
	else if (tag == "Slider")
	{
		playingWidgetsLayerSlider();
	}
	else if (tag == "TextField")
	{
		playingWidgetsLayerTextField();
	}
	else if (tag == "Timemap")
	{
		playingWidgetsLayerTilemap();
	}
	else if (tag == "Particle")
	{
		playingWidgetsLayerParticle();
	}
	else if (tag == "Parallax")
	{
		playingWidgetsLayerParallax();
	}
}

static void playingWidgetsLayerLable()
{
	Layer* l = WidgetLabelLayer::create();
	Scene* playingScene = Director::getInstance()->getRunningScene();
	playingScene->addChild(l);
}

static void playingWidgetsLayerMenu()
{
	Layer* l = WidgetMenuLayer::create();
	Scene* playingScene = Director::getInstance()->getRunningScene();
	playingScene->addChild(l);
}

static void playingWidgetsLayerButton()
{
	Layer* l = WidgetButtonLayer::create();
	Scene* playingScene = Director::getInstance()->getRunningScene();
	playingScene->addChild(l);
}
static void playingWidgetsLayerCheckbox()
{
	Layer* l = WidgetCheckboxLayer::create();
	Scene* playingScene = Director::getInstance()->getRunningScene();
	playingScene->addChild(l);
}

static void playingWidgetsLayerLoadingBar()
{
	Layer* l = WidgetLoadingbarLayer::create();
	Scene* playingScene = Director::getInstance()->getRunningScene();
	playingScene->addChild(l);
}

static void playingWidgetsLayerSlider()
{
	Layer* l = WidgetSliderLayer::create();
	Scene* playingScene = Director::getInstance()->getRunningScene();
	playingScene->addChild(l);
}
static void playingWidgetsLayerTextField()
{
	Layer* l = WidgetTextfieldLayer::create();
	Scene* playingScene = Director::getInstance()->getRunningScene();
	playingScene->addChild(l);
}

static void playingWidgetsLayerTilemap()
{
	Layer* l = WidgetTilemapLayer::create();
	Scene* playingScene = Director::getInstance()->getRunningScene();
	playingScene->addChild(l);
}
static void playingWidgetsLayerParticle()
{
	Layer* l = WidgetParticleLayer::create();
	Scene* playingScene = Director::getInstance()->getRunningScene();
	playingScene->addChild(l);
}

static void playingWidgetsLayerParallax()
{
	Layer* l = WidgetParallaxLayer::create();
	Scene* playingScene = Director::getInstance()->getRunningScene();
	playingScene->addChild(l);
}