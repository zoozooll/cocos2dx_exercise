#include "WidgetCheckboxLayer.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace cocos2d::ui;

WidgetCheckboxLayer::WidgetCheckboxLayer()
{
}


WidgetCheckboxLayer::~WidgetCheckboxLayer()
{
}

bool WidgetCheckboxLayer::init()
{
	Director* dire = Director::getInstance();
	Rect visibleRect = dire->getOpenGLView()->getVisibleRect();
	Size visibleSize = dire->getVisibleSize();
	Vec2 origin = dire->getVisibleOrigin();

	int index = 2;
	LabelTTF* label = LabelTTF::create("Label", "Marker Felt.ttf", 25);
	Vec2 showingBase = Vec2(visibleRect.origin.x + visibleRect.size.width * 0.5f, visibleRect.origin.y + visibleRect.size.height);
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

	// This is for Checkbox section of Programmers guide;
	CheckBox* checkBox = CheckBox::create("CheckBox_Normal.png",
		"CheckBox_Press.png",
		"CheckBoxNode_Normal.png",
		"CheckBox_Disable.png",
		"CheckBoxNode_Disable.png");
	checkBox->setPosition(Vec2(showingBase.x, showingBase.y));
	checkBox->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
	{
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			CCLOG("CheckBox TouchEventType::BEGAN");
			break;
		case cocos2d::ui::Widget::TouchEventType::MOVED:
			CCLOG("CheckBox TouchEventType::MOVED");
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			CCLOG("CheckBox TouchEventType::ENDED");
			break;
		case cocos2d::ui::Widget::TouchEventType::CANCELED:
			CCLOG("CheckBox TouchEventType::CANCELED");
			break;
		default:
			break;
		}
	});
	addChild(checkBox, 2);
	return true;
}