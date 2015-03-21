#include "WidgetLabelLayer.h"

USING_NS_CC;

WidgetLabelLayer::WidgetLabelLayer()
{
}


WidgetLabelLayer::~WidgetLabelLayer()
{
}

bool WidgetLabelLayer::init()
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
	Label* myLabel = Label::createWithBMFont("bitmapRed.fnt", "LabelBMFont");
	myLabel->setPosition(showingBase.x, showingBase.y - 2 * 40);
	addChild(myLabel, 2);

	// 2. LabelTTF.
	Label* myLabel2 = Label::create("Label TTF", "Marker Felt.ttf", 25);
	myLabel2->setPosition(showingBase.x, showingBase.y - (++index) * 40);
	addChild(myLabel2, 2);

	// 3. LabelTTF with TTFConfig.
	//TTFConfig labelConfig;
	//labelConfig.fontFilePath = "Marker Felt.ttf";
	//labelConfig.fontSize = 28;
	//Label* myLabel3 = Label::createWithTTF(labelConfig, "Label TTF with TTFConfig");
	//myLabel3->setPosition(showingBase.x, showingBase.y - (++index) * 40);
	//addChild(myLabel3, 2);

	// 4. Label using system font.
	Label* myLabel4 = Label::createWithSystemFont("Label with system font", "Arial", 25);
	myLabel4->setPosition(showingBase.x, showingBase.y - (++index) * 40);
	addChild(myLabel4, 2);

	// 5. LabelTTF with shadow,.
	Label* myLabel5 = Label::create("Label TTF with shadow", "Marker Felt.ttf", 25);
	myLabel5->setPosition(showingBase.x, showingBase.y - (++index) * 40);
	myLabel5->enableShadow();
	addChild(myLabel5, 2);

	// 6. LabelTTF with outline.
	Label* myLabel6 = Label::create("Label TTF with outline", "Marker Felt.ttf", 25);
	myLabel6->setPosition(showingBase.x, showingBase.y - (++index) * 40);
	myLabel6->enableOutline(Color4B::WHITE);
	myLabel6->setColor(Color3B::BLUE);
	addChild(myLabel6, 2);

	// 7. LabelTTF with glow,.
	Label* myLabel7 = Label::create("Label TTF with glow", "Marker Felt.ttf", 25);
	myLabel7->setPosition(showingBase.x, showingBase.y - (++index) * 40);
	myLabel7->enableGlow(Color4B::WHITE);
	myLabel7->setColor(Color3B::RED);
	addChild(myLabel7, 2);
	return true;
}