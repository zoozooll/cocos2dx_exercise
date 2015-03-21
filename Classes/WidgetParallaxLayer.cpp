#include "WidgetParallaxLayer.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

WidgetParallaxLayer::WidgetParallaxLayer()
{
}


WidgetParallaxLayer::~WidgetParallaxLayer()
{
}

bool WidgetParallaxLayer::init()
{
	Director* dire = Director::getInstance();
	Rect visibleRect = dire->getOpenGLView()->getVisibleRect();
	Size visibleSize = dire->getVisibleSize();
	Vec2 origin = dire->getVisibleOrigin();

	int index = 2;
	LabelTTF* label = LabelTTF::create("Parallax", "Marker Felt.ttf", 25);
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

	// This is for Parallax section of Programmers guide;
	ParallaxNode* parallax = ParallaxNode::create();
	int verts = 4;
	Color4F color1 = Color4F(1.0f, 0.1f, 0.3f, 1.0f);
	
	
	Vec2 box1[] = { Vec2::ZERO, Vec2(0, 200), Vec2(600, 200), Vec2(600, 0) };

	
	DrawNode* layer1 = DrawNode::create();
	layer1->setContentSize(Size(600, 200));
	layer1->drawPolygon(box1, verts, color1, 0, color1);
	layer1->setPosition(Vec2(showingBase.x, showingBase.y - (index++) * 40));
	parallax->addChild(layer1, -1, Vec2(0.4f, 0.5f), Vec2::ZERO);

	Color4F color2 = Color4F(0.5f, 0.6f, 0.4f, 1.0f);
	Vec2 box2[] = { Vec2::ZERO, Vec2(0, 300), Vec2(800, 300), Vec2(800, 0) };
	DrawNode* layer2 = DrawNode::create();
	layer2->setContentSize(Size(800, 300));
	layer2->drawPolygon(box2, verts, color2, 0, color2);
	layer2->setPosition(Vec2(showingBase.x, showingBase.y - (index++) * 60));
	parallax->addChild(layer2, -1, Vec2(2.2f, 1.0f), Vec2(0, -200));

	Color4F color3 = Color4F(0.0f, 1.0f, 0.5f, 1.0f);
	Vec2 box3[] = { Vec2::ZERO, Vec2(0, 500), Vec2(1000, 500), Vec2(1000, 0) };
	DrawNode* layer3 = DrawNode::create();
	layer3->setContentSize(Size(1000, 500));
	layer3->drawPolygon(box3, verts, color3, 0, color3);
	layer3->setPosition(Vec2(showingBase.x, showingBase.y - (index++) * 60));
	parallax->addChild(layer3, -1, Vec2(3.0f, 2.5f), Vec2(200, 800));

	MoveBy* goUp = MoveBy::create(4, Vec2(0, -250));
	MoveBy* goDown = goUp->reverse();
	MoveBy* goLeft = MoveBy::create(8, Vec2(-500, 0));
	MoveBy* goBack = goLeft->reverse();
	Sequence* seq = Sequence::create(goUp, goLeft, goDown, goBack, nullptr);
	parallax->runAction(RepeatForever::create(seq));
	addChild(parallax, 1);
	return true;
}