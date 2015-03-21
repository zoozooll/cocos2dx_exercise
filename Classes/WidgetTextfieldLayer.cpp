#include "WidgetTextfieldLayer.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

WidgetTextfieldLayer::WidgetTextfieldLayer()
{
}


WidgetTextfieldLayer::~WidgetTextfieldLayer()
{
}

bool WidgetTextfieldLayer::init()
{
	Director* dire = Director::getInstance();
	Rect visibleRect = dire->getOpenGLView()->getVisibleRect();
	Size visibleSize = dire->getVisibleSize();
	Vec2 origin = dire->getVisibleOrigin();

	int index = 2;
	LabelTTF* label = LabelTTF::create("Label", "Marker Felt.ttf", 25);
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

	// This is for Labels section of Programmers guide;

	// 1. BMFont;
	TextField* textField = TextField::create("Text Field", "Marker Felt.ttf", 30);
	textField->setMaxLength(25);
	textField->setPosition(Vec2(showingBase.x, showingBase.y - (++index) * 40));
	addChild(textField, 2);
	return true;
}