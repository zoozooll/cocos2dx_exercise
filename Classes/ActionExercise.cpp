#include "ActionExercise.h"
#include "ClockBackgroundScene.h"

USING_NS_CC;

static const char* MenuTitle1 = "First: Create a Sprite";
static const char* MenuTitle2 = "MoveTo/MoveBy";
static const char* MenuTitle3 = "FadeIn/FadeOut";
static const char* MenuTitle4 = "Animate";
static const char* MenuTitle5 = "RotateTo/RotateBy";
static const char* MenuTitle6 = "ScaleTo/ScaleBy";
static const char* MenuTitle7 = "TintTo/TintBy";
static const char* MenuTitle8 = "Ease";
static const char* MenuTitle9 = "Sequence";
static const char* MenuTitle10 = "Spawn";
static const char* MenuTitle11 = "Reverse";

static void OnMenuClicked1(Ref *sender);
static void OnMenuClicked2(Ref *sender);
static void OnMenuClicked3(Ref *sender);
static void OnMenuClicked4(Ref *sender);
static void OnMenuClicked5(Ref *sender);
static void OnMenuClicked6(Ref *sender);
static void OnMenuClicked7(Ref *sender);
static void OnMenuClicked8(Ref *sender);
static void OnMenuClicked9(Ref *sender);
static void OnMenuClicked10(Ref *sender);
static void OnMenuClicked11(Ref *sender);

ActionExercise::ActionExercise()
{
}


ActionExercise::~ActionExercise()
{
}


Scene* ActionExercise::createScene()
{
	
	Scene* scene = Scene::create();
	// 'layer' is an autorelease object
	ActionExercise* layer = ActionExercise::create();
	layer->setName("menuNode");
	// add layer as a child to scene
	scene->addChild(layer);
	return scene;
}

bool ActionExercise::init()
{
	Director* dir = Director::getInstance();
	Size visibleSize = dir->getVisibleSize();
	Vec2 origin = dir->getVisibleOrigin();
	Size playingSize = Size(visibleSize.width, visibleSize.height * 7.f / 8.f);

	MenuItemImage* closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(ActionExercise::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	// create menu, it's an autorelease object
	Menu* menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	Node* nodeItems = Node::create();
	nodeItems->setName("nodeItems");
	int index = 2;

	MenuItemFont* menuItem1 = MenuItemFont::create(MenuTitle1, CC_CALLBACK_1(ActionExercise::menuClickedCallback, this));
	menuItem1->setFontNameObj("Marker Felt.ttf");
	menuItem1->setFontSizeObj(32);
	menuItem1->setName("menuItem1");
	menuItem1->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2).x,
		(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height).y - (index)* 40));

	MenuItemFont* menuItem2 = MenuItemFont::create(MenuTitle2, CC_CALLBACK_1(ActionExercise::menuClickedCallback, this));
	menuItem2->setFontNameObj("Marker Felt.ttf");
	menuItem2->setFontSizeObj(32);
	menuItem2->setName("menuItem2");
	menuItem2->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2).x,
		(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height).y - (++index)* 40));

	MenuItemFont* menuItem3 = MenuItemFont::create(MenuTitle3, CC_CALLBACK_1(ActionExercise::menuClickedCallback, this));
	menuItem3->setFontNameObj("Marker Felt.ttf");
	menuItem3->setFontSizeObj(32);
	menuItem3->setName("menuItem3");
	menuItem3->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2).x,
		(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height).y - (++index)* 40));

	MenuItemFont* menuItem4 = MenuItemFont::create(MenuTitle4, CC_CALLBACK_1(ActionExercise::menuClickedCallback, this));
	menuItem4->setFontNameObj("Marker Felt.ttf");
	menuItem4->setFontSizeObj(32);
	menuItem4->setName("menuItem4");
	menuItem4->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2).x,
		(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height).y - (++index)* 40));

	MenuItemFont* menuItem5 = MenuItemFont::create(MenuTitle5, CC_CALLBACK_1(ActionExercise::menuClickedCallback, this));
	menuItem5->setFontNameObj("Marker Felt.ttf");
	menuItem5->setFontSizeObj(32);
	menuItem5->setName("menuItem5");
	menuItem5->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2).x,
		(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height).y - (++index)* 40));

	MenuItemFont* menuItem6 = MenuItemFont::create(MenuTitle6, CC_CALLBACK_1(ActionExercise::menuClickedCallback, this));
	menuItem6->setFontNameObj("Marker Felt.ttf");
	menuItem6->setFontSizeObj(32);
	menuItem6->setName("menuItem6");
	menuItem6->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2).x,
		(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height).y - (++index)* 40));

	MenuItemFont* menuItem7 = MenuItemFont::create(MenuTitle7, CC_CALLBACK_1(ActionExercise::menuClickedCallback, this));
	menuItem7->setFontNameObj("Marker Felt.ttf");
	menuItem7->setFontSizeObj(32);
	menuItem7->setName("menuItem7");
	menuItem7->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2).x,
		(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height).y - (++index)* 40));

	MenuItemFont* menuItem8 = MenuItemFont::create(MenuTitle8, CC_CALLBACK_1(ActionExercise::menuClickedCallback, this));
	menuItem8->setFontNameObj("Marker Felt.ttf");
	menuItem8->setFontSizeObj(32);
	menuItem8->setName("menuItem8");
	menuItem8->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2).x,
		(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height).y - (++index)* 40));

	MenuItemFont* menuItem9 = MenuItemFont::create(MenuTitle9, CC_CALLBACK_1(ActionExercise::menuClickedCallback, this));
	menuItem9->setFontNameObj("Marker Felt.ttf");
	menuItem9->setFontSizeObj(32);
	menuItem9->setName("menuItem9");
	menuItem9->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2).x,
		(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height).y - (++index)* 40));

	MenuItemFont* menuItem10 = MenuItemFont::create(MenuTitle10, CC_CALLBACK_1(ActionExercise::menuClickedCallback, this));
	menuItem10->setFontNameObj("Marker Felt.ttf");
	menuItem10->setFontSizeObj(32);
	menuItem10->setName("menuItem10");
	menuItem10->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2).x,
		(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height).y - (++index)* 40));

	MenuItemFont* menuItem11 = MenuItemFont::create(MenuTitle11, CC_CALLBACK_1(ActionExercise::menuClickedCallback, this));
	menuItem11->setFontNameObj("Marker Felt.ttf");
	menuItem11->setFontSizeObj(32);
	menuItem11->setName("menuItem11");
	menuItem11->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2).x,
		(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height).y - (++index)* 40));

	MenuItemFont* menuItemNext = MenuItemFont::create("Jump to Next Scene", CC_CALLBACK_1(ActionExercise::menuClickedCallback, this));
	menuItemNext->setFontNameObj("Marker Felt.ttf");
	menuItemNext->setFontSizeObj(32);
	menuItemNext->setName("menuItemNext");
	menuItemNext->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2).x,
		(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height).y - (++index) * 40));
	
	Menu* menu1 = Menu::create(menuItem1, menuItem2, menuItem3, menuItem4, menuItem5, menuItem6, menuItem7, menuItem8, menuItem9, menuItem10, menuItem11, menuItemNext, NULL);
	menu1->setName("menu");
	menu1->setPosition(Vec2::ZERO);
	addChild(menu1, 1);

	return true;
}

void ActionExercise::menuCloseCallback(cocos2d::Ref* pSender)
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

void ActionExercise::menuClickedCallback(cocos2d::Ref* pSender)
{
	std::string tag = ((Node*)pSender)->getName();
	if (tag == "menuItem1")
	{
		OnMenuClicked1(pSender);
	}
	else if (tag == "menuItem2")
	{
		OnMenuClicked2(pSender);
	}
	else if (tag == "menuItem3")
	{
		OnMenuClicked3(pSender);
	}
	else if (tag == "menuItem4")
	{
		OnMenuClicked4(pSender);
	}
	else if (tag == "menuItem5")
	{
		OnMenuClicked5(pSender);
	}
	else if (tag == "menuItem6")
	{
		OnMenuClicked6(pSender);
	}
	else if (tag == "menuItem7")
	{
		OnMenuClicked7(pSender);
	}
	else if (tag == "menuItem7")
	{
		OnMenuClicked7(pSender);
	}
	else if (tag == "menuItem8")
	{
		OnMenuClicked8(pSender);
	}
	else if (tag == "menuItem9")
	{
		OnMenuClicked9(pSender);
	}
	else if (tag == "menuItem10")
	{
		OnMenuClicked10(pSender);
	}
	else if (tag == "menuItem11")
	{
		OnMenuClicked11(pSender);
	}
	else if (tag == "menuItemNext")
	{
		Director::getInstance()->replaceScene(TransitionFlipX::create(2, ClockBackgroundScene::createScene()));
	}
}

static void OnMenuClicked1(Ref *sender)
{
	Scene* scene = Director::getInstance()->getRunningScene();

	Sprite* newSprite = Sprite::create("Blue_Front1.png");
	newSprite->setPosition(100, 256);
	newSprite->setName("sprite1");
	newSprite->setAnchorPoint(Vec2(0.5f, 0.5f));
	scene->addChild(newSprite, 1);
	Sprite* point1 = Sprite::create("dot.png");
	point1->setName("point1");
	point1->setPosition(newSprite->getPosition());
	scene->addChild(point1, 2);

	Sprite* newSprite2 = Sprite::create("Blue_Front1.png");
	newSprite2->setPosition(100, 256);
	newSprite2->setName("sprite2");
	newSprite2->setAnchorPoint(Vec2(0.5f, 0.5f));
	scene->addChild(newSprite2, 1);

}

static void OnMenuClicked2(Ref *sender)
{
	Scene* scene = Director::getInstance()->getRunningScene();
	scene->removeChildByName("sprite2");
	scene->removeChildByName("sprite3");
	scene->removeChildByName("point2");
	scene->removeChildByName("point3");

	Sprite* newSprite2 = Sprite::create("Blue_Front1.png");
	newSprite2->setPosition(100, 256);
	newSprite2->setName("sprite2");
	newSprite2->setAnchorPoint(Vec2(0.5f, 0.5f));
	scene->addChild(newSprite2, 1);

	MoveBy* moveBy = MoveBy::create(2, Point(500.f, 0.f));
	DelayTime* delay = DelayTime::create(2.f);
	Sequence* sequence = Sequence::create(moveBy, delay, NULL);
	newSprite2->runAction(sequence);

	Sprite* newSprite3 = Sprite::create("Blue_Front1.png");
	newSprite3->setPosition(100, 256);
	newSprite3->setName("sprite3");
	newSprite3->setAnchorPoint(Vec2(0.5f, 0.5f));
	scene->addChild(newSprite3, 1);

	MoveTo* moveTo = MoveTo::create(2, Point(500.f, 0.f));
	Sequence* sequence2 = Sequence::create(moveTo, delay, NULL);
	newSprite3->runAction(sequence2);
}

static void OnMenuClicked3(Ref *sender)
{
	Scene* scene = Director::getInstance()->getRunningScene();
	scene->removeChildByName("sprite2");
	scene->removeChildByName("sprite3");
	scene->removeChildByName("point2");
	scene->removeChildByName("point3");

	Sprite* newSprite2 = Sprite::create("Blue_Front1.png");
	newSprite2->setPosition(300, 256);
	newSprite2->setName("sprite2");
	newSprite2->setAnchorPoint(Vec2(0.5f, 0.5f));
	scene->addChild(newSprite2, 1);

	FadeIn* faceIn = FadeIn::create(1.0f);
	newSprite2->runAction(faceIn);

	Sprite* newSprite3 = Sprite::create("Blue_Front1.png");
	newSprite3->setPosition(500, 256);
	newSprite3->setName("sprite3");
	newSprite3->setAnchorPoint(Vec2(0.5f, 0.5f));
	scene->addChild(newSprite2, 1);

	FadeOut* faceOut = FadeOut::create(2.0f);
	newSprite3->runAction(faceOut);
}

static void OnMenuClicked4(Ref *sender)
{
	Scene* scene = Director::getInstance()->getRunningScene();
	scene->removeChildByName("sprite2");
	scene->removeChildByName("sprite3");
	scene->removeChildByName("point2");
	scene->removeChildByName("point3");

	Sprite* newSprite2 = Sprite::create("Blue_Front1.png");
	newSprite2->setPosition(300, 256);
	newSprite2->setName("sprite2");
	newSprite2->setAnchorPoint(Vec2(0.5f, 0.5f));
	scene->addChild(newSprite2, 1);
	
	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(12);
	animFrames.pushBack(SpriteFrame::create("Blue_Front1.png", Rect(0, 0, 65, 81)));
	animFrames.pushBack(SpriteFrame::create("Blue_Front2.png", Rect(0, 0, 65, 81)));
	animFrames.pushBack(SpriteFrame::create("Blue_Front3.png", Rect(0, 0, 65, 81)));
	animFrames.pushBack(SpriteFrame::create("Blue_Left1.png", Rect(0, 0, 65, 81)));
	animFrames.pushBack(SpriteFrame::create("Blue_Left2.png", Rect(0, 0, 65, 81)));
	animFrames.pushBack(SpriteFrame::create("Blue_left3.png", Rect(0, 0, 65, 81)));
	animFrames.pushBack(SpriteFrame::create("Blue_Back1.png", Rect(0, 0, 65, 81)));
	animFrames.pushBack(SpriteFrame::create("Blue_Back2.png", Rect(0, 0, 65, 81)));
	animFrames.pushBack(SpriteFrame::create("Blue_Back3.png", Rect(0, 0, 65, 81)));
	animFrames.pushBack(SpriteFrame::create("Blue_Right1.png", Rect(0, 0, 65, 81)));
	animFrames.pushBack(SpriteFrame::create("Blue_Right2.png", Rect(0, 0, 65, 81)));
	animFrames.pushBack(SpriteFrame::create("Blue_Right3.png", Rect(0, 0, 65, 81)));
	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	Animate* animate = Animate::create(animation);
	newSprite2->runAction(RepeatForever::create(animate));
}

static void OnMenuClicked5(Ref *sender)
{
	Scene* scene = Director::getInstance()->getRunningScene();
	scene->removeChildByName("sprite2");
	scene->removeChildByName("sprite3");
	scene->removeChildByName("point2");
	scene->removeChildByName("point3");

	Sprite* newSprite2 = Sprite::create("Blue_Front1.png");
	newSprite2->setPosition(300, 256);
	newSprite2->setName("sprite2");
	newSprite2->setAnchorPoint(Vec2(0.5f, 0.5f));
	scene->addChild(newSprite2, 1);
	Sprite* point2 = Sprite::create("dot.png");
	point2->setPosition(300, 256);
	point2->setName("point2");
	scene->addChild(point2, 2);

	RotateBy* rotateBy = RotateBy::create(2.0f, 40.f);

	newSprite2->runAction(rotateBy);

	Sprite* newSprite3 = Sprite::create("Blue_Front1.png");
	newSprite3->setPosition(500, 256);
	newSprite3->setName("sprite3");
	newSprite3->setAnchorPoint(Vec2(0.5f, 0.5f));
	scene->addChild(newSprite3, 1);
	Sprite* point3 = Sprite::create("dot.png");
	point3->setPosition(500, 256);
	point3->setName("point3");
	scene->addChild(point3, 2);

	RotateTo* rotateTo = RotateTo::create(2.0f, -20.f);
	newSprite3->runAction(rotateTo);
}

static void OnMenuClicked6(Ref *sender)
{
	Scene* scene = Director::getInstance()->getRunningScene();
	scene->removeChildByName("sprite2");
	scene->removeChildByName("sprite3");
	scene->removeChildByName("point2");
	scene->removeChildByName("point3");

	Sprite* newSprite2 = Sprite::create("Blue_Front1.png");
	newSprite2->setPosition(300, 256);
	newSprite2->setName("sprite2");
	newSprite2->setAnchorPoint(Vec2(0.5f, 0.5f));
	scene->addChild(newSprite2, 1);
	Sprite* point2 = Sprite::create("dot.png");
	point2->setPosition(300, 256);
	point2->setName("point2");
	scene->addChild(point2, 2);

	ScaleBy* scaleBy = ScaleBy::create(2.0f, 2.0f);
	newSprite2->runAction(scaleBy);

	Sprite* newSprite3 = Sprite::create("Blue_Front1.png");
	newSprite3->setPosition(500, 256);
	newSprite3->setName("sprite3");
	newSprite3->setAnchorPoint(Vec2(0.5f, 0.5f));
	scene->addChild(newSprite3, 1);
	Sprite* point3 = Sprite::create("dot.png");
	point3->setPosition(500, 256);
	point3->setName("point3");
	scene->addChild(point3, 2);

	ScaleTo* scaleTo = ScaleTo::create(2.0f, 0.5f);
	newSprite3->runAction(scaleTo);
}

static void OnMenuClicked7(Ref *sender)
{
	Scene* scene = Director::getInstance()->getRunningScene();
	scene->removeChildByName("sprite2");
	scene->removeChildByName("sprite3");
	scene->removeChildByName("point2");
	scene->removeChildByName("point3");

	Sprite* newSprite2 = Sprite::create("Blue_Front1.png");
	newSprite2->setPosition(300, 256);
	newSprite2->setName("sprite2");
	newSprite2->setAnchorPoint(Vec2(0.5f, 0.5f));
	scene->addChild(newSprite2, 1);

	TintBy* tintBy = TintBy::create(2.0f, 120.f, 120.f, 0.f);
	newSprite2->runAction(tintBy);

	Sprite* newSprite3 = Sprite::create("Blue_Front1.png");
	newSprite3->setPosition(500, 256);
	newSprite3->setName("sprite3");
	newSprite3->setAnchorPoint(Vec2(0.5f, 0.5f));
	scene->addChild(newSprite3, 1);

	TintTo* tintTo = TintTo::create(2.0f, 120.f, 0.f, 0.f);
	newSprite3->runAction(tintTo);
}

static void OnMenuClicked8(Ref *sender)
{
	Scene* scene = Director::getInstance()->getRunningScene();
	scene->removeChildByName("sprite2");
	scene->removeChildByName("sprite3");
	scene->removeChildByName("point2");
	scene->removeChildByName("point3");

	Sprite* newSprite2 = Sprite::create("White_Front1.png");
	newSprite2->setPosition(100, 256);
	newSprite2->setName("sprite2");
	newSprite2->setAnchorPoint(Vec2(0.5f, 0.5f));
	scene->addChild(newSprite2, 1);

	MoveBy* move = MoveBy::create(2.0f, Point(200, Director::getInstance()->getVisibleSize().height - newSprite2->getContentSize().height));
	MoveBy* moveBack = move->reverse();
	EaseBounceIn* movEaseIn = EaseBounceIn::create(move->clone());
	EaseBounceIn* movEaseInBack = (EaseBounceIn*)movEaseIn->reverse();
	DelayTime* delay = DelayTime::create(0.25f);
	Sequence* seq1 = Sequence::create(movEaseIn, delay, movEaseInBack, delay, NULL);
	newSprite2->runAction(RepeatForever::create(seq1));

	Sprite* newSprite3 = Sprite::create("LightBlue_Front1.png");
	newSprite3->setPosition(100, 256);
	newSprite3->setName("sprite3");
	newSprite3->setAnchorPoint(Vec2(0.5f, 0.5f));
	scene->addChild(newSprite3, 1);
	EaseBounceOut* movEaseOut = EaseBounceOut::create(move->clone());
	EaseBounceOut* movEaseOutBack = (EaseBounceOut*)movEaseOut->reverse();
	Sequence* seq2 = Sequence::create(movEaseOut, delay, movEaseOutBack, delay, NULL);
	newSprite3->runAction(seq2);
}

static void OnMenuClicked9(Ref *sender)
{
	Scene* scene = Director::getInstance()->getRunningScene();
	scene->removeChildByName("sprite2");
	scene->removeChildByName("sprite3");
	scene->removeChildByName("point2");
	scene->removeChildByName("point3");

	Sprite* newSprite2 = Sprite::create("Blue_Front1.png");
	newSprite2->setPosition(300, 256);
	newSprite2->setName("sprite2");
	newSprite2->setAnchorPoint(Vec2(0.5f, 0.5f));
	scene->addChild(newSprite2, 1);

	JumpBy* jumpBy = JumpBy::create(0.5f, Point(0.0f, 0.f), 100.f, 1);
	CallFunc* callbackJump = CallFunc::create([]() { log("Jumped!"); });
	RotateTo* rotateTo = RotateTo::create(2.0f, 90);
	CallFunc* callbackRotate = CallFunc::create([]() { log("Rotated!"); });
	Sequence* seq = Sequence::create(jumpBy, callbackJump, rotateTo, callbackRotate, NULL);
	newSprite2->runAction(seq);
}

static void OnMenuClicked10(Ref *sender)
{
	Scene* scene = Director::getInstance()->getRunningScene();
	scene->removeChildByName("sprite2");
	scene->removeChildByName("sprite3");
	scene->removeChildByName("point2");
	scene->removeChildByName("point3");

	Sprite* newSprite2 = Sprite::create("Blue_Front1.png");
	newSprite2->setPosition(100, 256);
	newSprite2->setName("sprite2");
	newSprite2->setAnchorPoint(Vec2(0.5f, 0.5f));
	scene->addChild(newSprite2, 1);

	// create a few actions
	MoveBy* moveBy = MoveBy::create(10, Point(400, 100));
	FadeTo* fadeTo = FadeTo::create(2.0f, 120.0f);

	// running the above Actions with Spawn.
	Spawn* mySpawn = Spawn::createWithTwoActions(moveBy, fadeTo);
	newSprite2->runAction(mySpawn);
}

static void OnMenuClicked11(Ref *sender)
{
	Scene* scene = Director::getInstance()->getRunningScene();
	scene->removeChildByName("sprite2");
	scene->removeChildByName("sprite3");
	scene->removeChildByName("point2");
	scene->removeChildByName("point3");

	Sprite* newSprite2 = Sprite::create("Blue_Front1.png");
	newSprite2->setPosition(100, 256);
	newSprite2->setName("sprite2");
	newSprite2->setAnchorPoint(Vec2(0.5f, 0.5f));
	scene->addChild(newSprite2, 1);

	// create a few Actions
	MoveBy* moveBy = MoveBy::create(2.0f, Point(500, 0));
	ScaleBy* scaleBy = ScaleBy::create(2.0f, 2.0f);
	DelayTime* delay = DelayTime::create(1.0f);

	// create a sequence
	Sequence* delaySequence = Sequence::create(delay, delay->clone(), delay->clone(), delay->clone(), NULL);

	Sequence* sequence = Sequence::create(moveBy, delay, scaleBy, delaySequence, NULL);

	newSprite2->runAction(sequence);

	newSprite2->runAction(sequence->reverse());
}