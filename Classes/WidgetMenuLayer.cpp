#include "WidgetMenuLayer.h"

USING_NS_CC;

WidgetMenuLayer::WidgetMenuLayer()
{
}


WidgetMenuLayer::~WidgetMenuLayer()
{
}

bool WidgetMenuLayer::init()
{
	Director* dire = Director::getInstance();
	Rect visibleRect = dire->getOpenGLView()->getVisibleRect();
	Size visibleSize = dire->getVisibleSize();
	Vec2 origin = dire->getVisibleOrigin();

	int index = 2;
	LabelTTF* label = LabelTTF::create("Menu and Menu Item", "Marker Felt.ttf", 25);
	Vec2 showingBase = Vec2(visibleRect.origin.x + visibleRect.size.width * 0.5f, visibleRect.origin.y + visibleRect.size.height * 0.5f);
	label->setPosition(showingBase.x, showingBase.y - 30);
	addChild(label, 1);

	label = LabelTTF::create("MainMenu", "Marker Felt.ttf", 25);
	MenuItemLabel* menuItem = MenuItemLabel::create(label);
	menuItem->setCallback([&](cocos2d::Ref *sender) {
		this->setVisible(false);
		Scene* scene = Director::getInstance()->getRunningScene();
		Layer* rootLayer = (Layer*)scene->getChildByName("rootLayer");
		rootLayer->setVisible(true);

	});

	Menu* menu = Menu::create(menuItem, nullptr);
	menu->setPosition(Vec2::ZERO);
	menuItem->setPosition(Vec2(visibleRect.origin.x + visibleRect.size.width - 80, visibleRect.origin.y + 25));
	addChild(menu, 1);

	// This is for Menu and Menu Item section of Programmers guide;
	Vector<MenuItem*> menuItems;
	// 1. 
	label = LabelTTF::create("Item 1", "Marker Felt.ttf", 32);
	MenuItemLabel* item = MenuItemLabel::create(label);
	item->setPosition(showingBase.x, showingBase.y - (++index) * 40);
	item->setCallback([&](Ref* sender)
	{
		CCLOG("item %d pushed", index);
	});
	menuItems.pushBack(item);

	// 2. 
	label = LabelTTF::create("Item 1", "Marker Felt.ttf", 32);
	item = MenuItemLabel::create(label);
	item->setPosition(showingBase.x, showingBase.y - (++index) * 40);
	item->setCallback([&](Ref* sender)
	{
		CCLOG("item %d pushed", index);
	});
	menuItems.pushBack(item);

	// 3. 
	label = LabelTTF::create("Item 1", "Marker Felt.ttf", 32);
	item = MenuItemLabel::create(label);
	item->setPosition(showingBase.x, showingBase.y - (++index) * 40);
	item->setCallback([&](Ref* sender)
	{
		CCLOG("item %d pushed", index);
	});
	menuItems.pushBack(item);
	
	Menu* menuContent = Menu::createWithArray(menuItems);
	menuContent->setPosition(Vec2::ZERO);
	addChild(menuContent, 2);
	return true;
}