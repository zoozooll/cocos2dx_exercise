#include "Charpter3.h"

USING_NS_CC;

static const char *TitleStep1 = "First: Create a sprite";
static const char *TitleStep2 = "Step2: Create a Sprite from a Rect";
static const char *TitleStep3 = "Step3: Create a Sprite from SpriteFrameCache";
static const char *TitleStep4 = "Step4: Create a Sprite from SpriteFrame";
static const char *TitleStep5 = "Step5: Scale a Sprite";
static const char *TitleStep6 = "Step6: Anchor Point and Sprite";
static const char *TitleStep7 = "Step7: Skew a Sprite";
static const char *TitleStep8 = "Step8: Rotate a Sprite";
static const char *TitleStep9 = "Step9: Change the Color of a Sprite";
static const char *TitleStep10 = "Step20: Change the Color of a Sprite";


static void RunStep1(Scene *scene, MenuItemFont *font);
static void RunStep2(Scene *scene, MenuItemFont *font);
static void RunStep3(Scene *scene, MenuItemFont *font);
static void RunStep4(Scene *scene, MenuItemFont *font);
static void RunStep5(Scene *scene, MenuItemFont *font);
static void RunStep6(Scene *scene, MenuItemFont *font);
static void RunStep7(Scene *scene, MenuItemFont *font);
static void RunStep8(Scene *scene, MenuItemFont *font);
static void RunStep9(Scene *scene, MenuItemFont *font);
static void RunStep10(Scene *scene, MenuItemFont *font);

Charpter3::Charpter3()
{
}


Charpter3::~Charpter3()
{
}

Scene* Charpter3::createScene()
{
	Scene *scene = Scene::create();

	Charpter3 *self = Charpter3::create();
	self->setName("root");
	scene->addChild(self);
	return scene;
}

bool Charpter3::init()
{
	Director *dirs = Director::sharedDirector();
	Size visibleSize = dirs->getVisibleSize();
	Vec2 origin = dirs->getVisibleOrigin();
	Size playingSize = Size(visibleSize.width, visibleSize.height * 7 / 8);

	Node *nodeItems = Node::create();
	nodeItems->setName("nodeItems");


	int index = 2;
	MenuItemFont *menuItem1 = MenuItemFont::create(TitleStep1);
	menuItem1->setFontNameObj("Marker Felt.ttf");
	menuItem1->setFontSizeObj(32);
	menuItem1->setName("menuItem1");
	menuItem1->setPosition(Vec2(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * 0.5f).x, Vec2(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height).y - (index)* 40);
	menuItem1->setCallback([&](cocos2d::Ref *sender) {
		
		Scene *scene = Director::getInstance()->getRunningScene();
		MenuItemFont *font = (MenuItemFont*)sender;
		static int step = 1;
		switch (step)
		{
		case 1:
		{
			step++;
			RunStep1(scene, font);
		}
			break;
		case 2:
		{
				  step++;
				  RunStep2(scene, font);
		}
			break;
		case 3:
		{
				  step++;
				  RunStep3(scene, font);
		}
			break;
		case 4:
		{
				  step++;
				  RunStep4(scene, font);
		}
			break;
		/*case 5:
		{
				  RunStep5(scene, font);
		}
			break;
		case 6:
		{
				  RunStep6(scene, font);
		}
			break;
		case 7:
		{
				  RunStep7(scene, font);
		}
			break;
		case 8:
		{
				  RunStep8(scene, font);
		}
			break;

		case 9:
		{
				  RunStep9(scene, font);
		}
			break;
		case 10:
		{
				  RunStep10(scene, font);
		}
			break;*/
		
		default:
			step = 1;
			break;
		}
		
	});

	/*MenuItemFont *menuItem2 = MenuItemFont::create("Next:Create a Sprite from a rect");
	menuItem2->setFontNameObj("fonts/Marker Felt.ttf");
	menuItem2->setFontSizeObj(32);
	menuItem2->setName("menuItem2");
	menuItem2->setVisible(false);
	menuItem2->setPosition(Vec2(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * 0.5f).x, Vec2(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height).y - (index)* 40);
	menuItem2->setCallback([&](Ref *sender) {
	Scene *scene = Director::getInstance()->getRunningScene();
	auto newSprite = Sprite::create("Blue_Front1.png");
	newSprite->setPosition(250, 256);
	newSprite->setName("sprite2");
	newSprite->setAnchorPoint(Vec2(0.5, 0.5));
	scene->addChild(newSprite, 1);

	Node *anode = scene->getChildByName("root");
	Node *anode1 = anode->getChildByName("menuNode");
	Node *bnode = anode1->getChildByName("menu");
	Node *cnode = bnode->getChildByName("menuItem2");
	cnode->setVisible(false);
	auto dnode = bnode->getChildByName("menuItem3");
	dnode->setVisible(true);
	});

	MenuItemFont *menuItem3 = MenuItemFont::create("Next:Create a Sprite from SpriteFrameCache");
	menuItem3->setFontNameObj("fonts/Marker Felt.ttf");
	menuItem3->setFontSizeObj(32);
	menuItem3->setName("menuItem3");
	menuItem3->setVisible(false);
	menuItem3->setPosition(Vec2(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * 0.5f).x, Vec2(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height).y - (index)* 40);
	menuItem3->setCallback([&](Ref *sender) {
	Scene *scene = Director::getInstance()->getRunningScene();
	SpriteFrameCache *newSpriteCache = SpriteFrameCache::getInstance();
	newSpriteCache->addSpriteFramesWithFile("sprites.plist");
	Sprite *newSprite = Sprite::createWithSpriteFrameName("Blue_Front1.png");

	newSprite->setPosition(400, 256);
	newSprite->setName("sprite3");
	newSprite->setAnchorPoint(Vec2(0.5, 0.5));
	scene->addChild(newSprite, 1);

	Node *anode = scene->getChildByName("root");
	Node *anode1 = anode->getChildByName("menuNode");
	Node *bnode = anode1->getChildByName("menu");
	Node *cnode = bnode->getChildByName("menuItem3");
	cnode->setVisible(false);
	auto dnode = bnode->getChildByName("menuItem4");
	dnode->setVisible(true);
	});

	MenuItemFont *menuItem4 = MenuItemFont::create("Next:Create a Sprite from SpriteFrame");
	menuItem4->setFontNameObj("Marker Felt.ttf");
	menuItem4->setFontSizeObj(32);
	menuItem4->setName("menuItem4");
	menuItem4->setVisible(false);
	menuItem4->setPosition(Vec2(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * 0.5f).x, Vec2(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height).y - (index)* 40);
	menuItem4->setCallback([&](Ref *sender) {
	Scene *scene = Director::getInstance()->getRunningScene();
	SpriteFrameCache *newSpriteCache = SpriteFrameCache::getInstance();
	newSpriteCache->addSpriteFramesWithFile("sprites.plist");
	SpriteFrame *spriteFrame = SpriteFrame::create("Blue_Front1.png", Rect(0, 0, 50, 50));
	Sprite *newSprite = Sprite::createWithSpriteFrame(spriteFrame);
	newSprite->setPosition(500, 256);
	newSprite->setName("sprite3");
	newSprite->setAnchorPoint(Vec2(0.5, 0.5));
	scene->addChild(newSprite, 1);

	Node *anode = scene->getChildByName("root");
	Node *anode1 = anode->getChildByName("menuNode");
	Node *bnode = anode1->getChildByName("menu");
	Node *cnode = bnode->getChildByName("menuItem3");
	cnode->setVisible(false);
	auto dnode = bnode->getChildByName("menuItem4");
	dnode->setVisible(true);
	});

	MenuItemFont *menuItem5 = MenuItemFont::create("Next:Scale a Sprite");
	menuItem5->setFontNameObj("Marker Felt.ttf");
	menuItem5->setFontSizeObj(32);
	menuItem5->setName("menuItem2");
	menuItem5->setVisible(false);
	menuItem5->setPosition(Vec2(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * 0.5f).x, Vec2(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height).y - (index)* 40);
	menuItem5->setCallback([&](Ref *sender) {
	Scene *scene = Director::getInstance()->getRunningScene();
	SpriteFrameCache *newSpriteCache = SpriteFrameCache::getInstance();
	newSpriteCache->addSpriteFramesWithFile("sprites.plist");
	SpriteFrame *spriteFrame = SpriteFrame::create("Blue_Front1.png", Rect(0, 0, 50, 50));
	Sprite *newSprite = Sprite::createWithSpriteFrame(spriteFrame);
	newSprite->setPosition(500, 256);
	newSprite->setName("sprite3");
	newSprite->setAnchorPoint(Vec2(0.5, 0.5));
	scene->addChild(newSprite, 1);

	Node *anode = scene->getChildByName("root");
	Node *anode1 = anode->getChildByName("menuNode");
	Node *bnode = anode1->getChildByName("menu");
	Node *cnode = bnode->getChildByName("menuItem3");
	cnode->setVisible(false);
	auto dnode = bnode->getChildByName("menuItem4");
	dnode->setVisible(true);
	});


	MenuItemFont *menuItem6 = MenuItemFont::create("Next:Anchor Point and Sprite");
	menuItem6->setFontNameObj("Marker Felt.ttf");
	menuItem6->setFontSizeObj(32);
	menuItem6->setName("menuItem6");
	menuItem6->setVisible(false);
	menuItem6->setPosition(Vec2(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * 0.5f).x, Vec2(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height).y - (index)* 40);


	MenuItemFont *menuItem7 = MenuItemFont::create("Next:Skew a Sprite");
	menuItem7->setFontNameObj("Marker Felt.ttf");
	menuItem7->setFontSizeObj(32);
	menuItem7->setName("menuItem7");
	menuItem7->setVisible(false);
	menuItem7->setPosition(Vec2(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * 0.5f).x, Vec2(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height).y - (index)* 40);


	MenuItemFont *menuItem8 = MenuItemFont::create("Next: Rotate a Sprite");
	menuItem8->setFontNameObj("Marker Felt.ttf");
	menuItem8->setFontSizeObj(32);
	menuItem8->setName("menuItem8");
	menuItem8->setVisible(false);
	menuItem8->setPosition(Vec2(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * 0.5f).x, Vec2(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height).y - (index)* 40);


	MenuItemFont *menuItem9 = MenuItemFont::create("Next: Change the Color of a Sprite");
	menuItem9->setFontNameObj("Marker Felt.ttf");
	menuItem9->setFontSizeObj(32);
	menuItem9->setName("menuItem9");
	menuItem9->setVisible(false);
	menuItem9->setPosition(Vec2(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * 0.5f).x, Vec2(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height).y - (index)* 40);


	MenuItemFont *menuItem10 = MenuItemFont::create("Next: Change the Color of a Sprite");
	menuItem10->setFontNameObj("Marker Felt.ttf");
	menuItem10->setFontSizeObj(32);
	menuItem10->setName("menuItem10");
	menuItem10->setVisible(false);
	menuItem10->setPosition(Vec2(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * 0.5f).x, Vec2(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height).y - (index)* 40);*/


	Menu *menu = Menu::create(menuItem1, NULL);
	menu->setName("menu");

	Node *menuNode = Node::create();
	menuNode->setName("menuNode");
	menuItem1->setPosition(Vec2::ZERO);
	//menuNode->addChild(menu, 1);
	addChild(menu);
	return true;
}

static void RunStep1(Scene *scene, MenuItemFont *font)
{

	auto newSprite = Sprite::create("Blue_Front1.png");
	newSprite->setPosition(100, 256);
	newSprite->setName("sprite1");
	newSprite->setAnchorPoint(Vec2(0.5, 0.5));
	scene->addChild(newSprite, 1);

	/*Node *anode = scene->getChildByName("root");
	Node *anode1 = anode->getChildByName("menuNode");
	Node *bnode = anode1->getChildByName("menu");
	Node *cnode = bnode->getChildByName("menuItem1");
	cnode->setVisible(false);
	auto dnode = bnode->getChildByName("menuItem2");
	dnode->setVisible(true);*/
	font->setString(TitleStep2);
}

static void RunStep2(Scene *scene, MenuItemFont *font)
{

	Sprite *newSprite = Sprite::create("Blue_Front1.png", Rect(0, 0, 50, 50));
	newSprite->setPosition(250, 256);
	newSprite->setName("sprite2");
	newSprite->setAnchorPoint(Vec2(0.5, 0.5));
	scene->addChild(newSprite, 1);
	font->setString(TitleStep3);
}

static void RunStep3(Scene *scene, MenuItemFont *font)
{
	SpriteFrameCache *spritecache = SpriteFrameCache::getInstance();
	spritecache->addSpriteFramesWithFile("sprites.plist");

	auto newSprite = Sprite::createWithSpriteFrameName("Blue_Front1.png");
	newSprite->setPosition(400, 256);
	newSprite->setName("sprite3");
	newSprite->setAnchorPoint(Vec2(0.5, 0.5));
	scene->addChild(newSprite, 1);
	font->setString(TitleStep4);
}

static void RunStep4(Scene *scene, MenuItemFont *font)
{

	SpriteFrameCache *spritecache = SpriteFrameCache::getInstance();
	spritecache->addSpriteFramesWithFile("sprites.plist");

	auto newspriteFrame = SpriteFrame::create("Blue_Front1.png", Rect(0, 0, 50, 50));

	auto newSprite = Sprite::createWithSpriteFrame(newspriteFrame);
	newSprite->setPosition(550, 256);
	newSprite->setName("sprite4");
	newSprite->setAnchorPoint(Vec2(0.5, 0.5));
	scene->addChild(newSprite, 1);
	font->setString(TitleStep5);
}

static void RunStep5(Scene *scene, MenuItemFont *font)
{
	scene->removeChildByName("sprite1");
	scene->removeChildByName("sprite2");
	scene->removeChildByName("sprite3");
	scene->removeChildByName("sprite4");

	Sprite * newSprite = Sprite::create("Blue_Front1.png");
	newSprite->setPosition(100.f, 256.f);
	newSprite->setName("sprite5");
	newSprite->setAnchorPoint(Vec2(0.5f, 0.5f));
	scene->addChild(newSprite, 1);
	font->setString(TitleStep6);
}

static void RunStep6(Scene *scene, MenuItemFont *font)
{

	auto newSprite = Sprite::create("Blue_Front1.png");
	newSprite->setPosition(100, 256);
	newSprite->setName("sprite1");
	newSprite->setAnchorPoint(Vec2(0.5, 0.5));
	scene->addChild(newSprite, 1);

	/*Node *anode = scene->getChildByName("root");
	Node *anode1 = anode->getChildByName("menuNode");
	Node *bnode = anode1->getChildByName("menu");
	Node *cnode = bnode->getChildByName("menuItem1");
	cnode->setVisible(false);
	auto dnode = bnode->getChildByName("menuItem2");
	dnode->setVisible(true);*/
	font->setString(TitleStep2);
}

static void RunStep7(Scene *scene, MenuItemFont *font)
{

	auto newSprite = Sprite::create("Blue_Front1.png");
	newSprite->setPosition(100, 256);
	newSprite->setName("sprite1");
	newSprite->setAnchorPoint(Vec2(0.5, 0.5));
	scene->addChild(newSprite, 1);

	/*Node *anode = scene->getChildByName("root");
	Node *anode1 = anode->getChildByName("menuNode");
	Node *bnode = anode1->getChildByName("menu");
	Node *cnode = bnode->getChildByName("menuItem1");
	cnode->setVisible(false);
	auto dnode = bnode->getChildByName("menuItem2");
	dnode->setVisible(true);*/
	font->setString(TitleStep2);
}

static void RunStep8(Scene *scene, MenuItemFont *font)
{

	auto newSprite = Sprite::create("Blue_Front1.png");
	newSprite->setPosition(100, 256);
	newSprite->setName("sprite1");
	newSprite->setAnchorPoint(Vec2(0.5, 0.5));
	scene->addChild(newSprite, 1);

	/*Node *anode = scene->getChildByName("root");
	Node *anode1 = anode->getChildByName("menuNode");
	Node *bnode = anode1->getChildByName("menu");
	Node *cnode = bnode->getChildByName("menuItem1");
	cnode->setVisible(false);
	auto dnode = bnode->getChildByName("menuItem2");
	dnode->setVisible(true);*/
	font->setString(TitleStep2);
}

static void RunStep9(Scene *scene, MenuItemFont *font)
{

	auto newSprite = Sprite::create("Blue_Front1.png");
	newSprite->setPosition(100, 256);
	newSprite->setName("sprite1");
	newSprite->setAnchorPoint(Vec2(0.5, 0.5));
	scene->addChild(newSprite, 1);

	/*Node *anode = scene->getChildByName("root");
	Node *anode1 = anode->getChildByName("menuNode");
	Node *bnode = anode1->getChildByName("menu");
	Node *cnode = bnode->getChildByName("menuItem1");
	cnode->setVisible(false);
	auto dnode = bnode->getChildByName("menuItem2");
	dnode->setVisible(true);*/
	font->setString(TitleStep2);
}

static void RunStep10(Scene *scene, MenuItemFont *font)
{

	auto newSprite = Sprite::create("Blue_Front1.png");
	newSprite->setPosition(100, 256);
	newSprite->setName("sprite1");
	newSprite->setAnchorPoint(Vec2(0.5, 0.5));
	scene->addChild(newSprite, 1);

	/*Node *anode = scene->getChildByName("root");
	Node *anode1 = anode->getChildByName("menuNode");
	Node *bnode = anode1->getChildByName("menu");
	Node *cnode = bnode->getChildByName("menuItem1");
	cnode->setVisible(false);
	auto dnode = bnode->getChildByName("menuItem2");
	dnode->setVisible(true);*/
	font->setString(TitleStep2);
}
