#include "SpriteExercise.h"
#include "ActionExercise.h"

USING_NS_CC;
static const char* FirstMenuLabel = "First: Create a Sprite";
static const char* Step2MenuLabel = "Step2: Create a Sprite from a Rect";
static const char* Step3MenuLabel = "Step3: Create a Sprite from SpriteFrameCache";
static const char* Step4MenuLabel = "Step4: Create a Sprite from SpriteFrame";
static const char* Step5MenuLabel = "Step5: Scale a Sprite";
static const char* Step6MenuLabel = "Step6: Anchor Point and Sprite";
static const char* Step7MenuLabel = "Step7: Skew a Sprite";
static const char* Step8MenuLabel = "Step8: Rotate a Sprite";
static const char* Step9MenuLabel = "Step9: Change the Color of a Sprite";
static const char* Step10MenuLabel = "Step10: Change the Color of a Sprite";
static const char* FinalMenuLabel = "Final: Clear and Goodbye";

static void DoStep1SpriteMemu(Scene* scene, MenuItemFont* menuItem);
static void DoStep2SpriteMemu(Scene* scene, MenuItemFont* menuItem);
static void DoStep3SpriteMemu(Scene* scene, MenuItemFont* menuItem);
static void DoStep4SpriteMemu(Scene* scene, MenuItemFont* menuItem);
static void DoStep5SpriteMemu(Scene* scene, MenuItemFont* menuItem);
static void DoStep6SpriteMemu(Scene* scene, MenuItemFont* menuItem);
static void DoStep7SpriteMemu(Scene* scene, MenuItemFont* menuItem);
static void DoStep8SpriteMemu(Scene* scene, MenuItemFont* menuItem);
static void DoStep9SpriteMemu(Scene* scene, MenuItemFont* menuItem);
static void DoStep10SpriteMemu(Scene* scene, MenuItemFont* menuItem);
static void DoFinalSpriteMemu(Scene* scene, MenuItemFont* menuItem);
static Scene* createScene3();

Scene* SpriteExercise::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = SpriteExercise::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SpriteExercise::init()
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
										   CC_CALLBACK_1(SpriteExercise::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
	menu->setName("menu");
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

	MenuItemFont *menuItem = MenuItemFont::create(FirstMenuLabel, CC_CALLBACK_1(SpriteExercise::menuClickedCallback, this));
    menuItem->setFontNameObj("Marker Felt.ttf");
    menuItem->setFontSizeObj(32);
    menuItem->setName("menuItem1");
    menuItem->setPosition(Vec2(origin.x+visibleSize.width * 0.5f, origin.y+visibleSize.height * 0.5f).x,
                          (Vec2(origin.x+visibleSize.width * 0.5f, origin.y+visibleSize.height).y - 2.0f * 40.f));
	menu->addChild(menuItem);

	MenuItemFont *menuItemNext = MenuItemFont::create("Jump to Next Scene", CC_CALLBACK_1(SpriteExercise::menuClickedCallback, this));
	menuItemNext->setFontNameObj("Marker Felt.ttf");
	menuItemNext->setFontSizeObj(32);
	menuItemNext->setName("menuItemNext");
	menuItemNext->setPosition(Vec2(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * 0.5f).x,
		(Vec2(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height).y - 4.0f * 40.f));
	menu->addChild(menuItemNext);
	
    return true;
}


void SpriteExercise::menuCloseCallback(Ref* pSender)
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




void SpriteExercise::menuClickedCallback(Ref* pSender)
{
	std::string name = ((Node*)pSender)->getName();

	if ("menuItemNext" == name)
	{
		Director::getInstance()->replaceScene(TransitionFade::create(0.5, createScene3(), Color3B(0, 255, 255)));
	}
	else
	{
		Scene *scene = Director::getInstance()->getRunningScene();

		MenuItemFont *menuItem = (MenuItemFont*)pSender;
		static int step = 1;
		switch (step) {
		case 1:
		{
				  DoStep1SpriteMemu(scene, menuItem);
				  step++;
		}
			break;
		case 2:
		{
				  DoStep2SpriteMemu(scene, menuItem);
				  step++;
		}
			break;
		case 3:
		{
				  DoStep3SpriteMemu(scene, menuItem);
				  step++;
		}
			break;
		case 4:
		{
				  DoStep4SpriteMemu(scene, menuItem);
				  step++;
		}
			break;
		case 5:
		{
				  DoStep5SpriteMemu(scene, menuItem);
				  step++;
		}
			break;

		case 6:
		{
				  step++;
				  DoStep6SpriteMemu(scene, menuItem);
		}
			break;
		case 7:
		{
				  step++;
				  DoStep7SpriteMemu(scene, menuItem);
		}
			break;
		case 8:
		{
				  step++;
				  DoStep8SpriteMemu(scene, menuItem);
		}
			break;
		case 9:
		{
				  step++;
				  DoStep9SpriteMemu(scene, menuItem);
		}
			break;
		case 10:
		{
				   step++;
				   DoStep10SpriteMemu(scene, menuItem);
		}
			break;

		default:
		{
				   step = 1;
				   DoFinalSpriteMemu(scene, menuItem);
		}
			break;
		}
	}
	
    
};

static Scene* createScene3()
{
	return ActionExercise::createScene();
}

static void DoStep1SpriteMemu(Scene* scene, MenuItemFont* menuItem)
{
    Sprite *newSprite = Sprite::create("Blue_Front1.png");
    newSprite->setPosition(100.f, 256.f);
    newSprite->setName("sprite1");
    newSprite->setAnchorPoint(Vec2(0.5f, 0.5f));
    scene->addChild(newSprite);
    menuItem->setString(Step2MenuLabel);
    
}

static void DoStep2SpriteMemu(Scene* scene, MenuItemFont* menuItem)
{
    Sprite* newSprite = Sprite::create("Blue_Front1.png", Rect(0, 0, 50, 50));
    newSprite->setPosition(250, 256);
    newSprite->setName("sprite2");
    newSprite->setAnchorPoint(Vec2(0.5f, 0.5f));
    scene->addChild(newSprite);
    menuItem->setString(Step3MenuLabel);
                        
}

static void DoStep3SpriteMemu(Scene* scene, MenuItemFont* menuItem)
{
    SpriteFrameCache* spritecache = SpriteFrameCache::getInstance();
    spritecache->addSpriteFramesWithFile("sprites.plist");
    
    Sprite* newSprite = Sprite::createWithSpriteFrameName("Blue_Front1.png");
    newSprite->setPosition(400, 256);
    newSprite->setName("sprite3");
    newSprite->setAnchorPoint(Vec2(0.5,0.5));
    scene->addChild(newSprite,1);
    menuItem->setString(Step4MenuLabel);
}

static void DoStep4SpriteMemu(Scene* scene, MenuItemFont* menuItem)
{
    SpriteFrameCache* spritecache = SpriteFrameCache::getInstance();
    spritecache->addSpriteFramesWithFile("sprites.plist");
    
    SpriteFrame* newspriteFrame = SpriteFrame::create("Blue_Front1.png", Rect(0,0,50,50));
    
    Sprite* newSprite = Sprite::createWithSpriteFrame(newspriteFrame);
    newSprite->setPosition(550, 256);
    newSprite->setName("sprite4");
    newSprite->setAnchorPoint(Vec2(0.5,0.5));
    scene->addChild(newSprite,1);
    menuItem->setString(Step5MenuLabel);
}

static void DoStep5SpriteMemu(Scene* scene, MenuItemFont* menuItem)
{
    scene->removeChildByName("sprite1");
    scene->removeChildByName("sprite2");
    scene->removeChildByName("sprite3");
    scene->removeChildByName("sprite4");
    
    Sprite *newSprite = Sprite::create();
    newSprite->setPosition(100.f, 256.f);
    newSprite->setName("sprite5");
    newSprite->setAnchorPoint(Vec2(0.5f, 0.5f));
    scene->addChild(newSprite, 1);
    Sprite *point00 = Sprite::create("dot.png");
    point00->setName("point00");
    point00->setPosition(newSprite->getPosition());
    scene->addChild(point00);
    
    Sprite *newSpriteScaleXY = Sprite::create("Blue_Front1.png");
    newSpriteScaleXY->setPosition(250, 256);
    newSpriteScaleXY->setName("sprite6");
    newSpriteScaleXY->setAnchorPoint(Vec2(0.5f, 0.5f));
    newSpriteScaleXY->setScale(2.0f);
    scene->addChild(newSpriteScaleXY);
    Sprite *pointXY = Sprite::create("dot.png");
    pointXY->setName("pointXY");
	pointXY->setPosition(newSpriteScaleXY->getPosition());
    scene->addChild(pointXY);
    
    Sprite *newSpriteScaleX = Sprite::create("Blue_Front1.png");
    newSpriteScaleX->setPosition(400, 256);
    newSpriteScaleX->setName("sprite7");
    newSpriteScaleX->setAnchorPoint(Vec2(0.5f, 0.5f));
    newSpriteScaleX->setScaleX(2.0f);
    scene->addChild(newSpriteScaleX);
    Sprite *pointX = Sprite::create("dot.png");
    pointX->setName("pointX");
	pointX->setPosition(newSpriteScaleX->getPosition());
    scene->addChild(pointX);
    
    Sprite *newSpriteScaleY = Sprite::create("Blue_Front1.png");
    newSpriteScaleY->setPosition(550, 256);
    newSpriteScaleY->setName("sprite8");
    newSpriteScaleY->setAnchorPoint(Vec2(0.5f, 0.5f));
    newSpriteScaleY->setScaleY(2.0f);
	scene->addChild(newSpriteScaleY);
    Sprite *pointY = Sprite::create("dot.png");
    pointY->setName("pointY");
	pointY->setPosition(newSpriteScaleY->getPosition());
    scene->addChild(pointY);
    
    menuItem->setString(Step6MenuLabel);
}

static void DoStep6SpriteMemu(Scene* scene, MenuItemFont* menuItem)
{
    scene->removeChildByName("sprite5");
    scene->removeChildByName("sprite6");
    scene->removeChildByName("sprite7");
    scene->removeChildByName("sprite8");
    scene->removeChildByName("point00");
    scene->removeChildByName("pointXY");
    scene->removeChildByName("pointX");
    scene->removeChildByName("pointY");
    
    Sprite *newSprite00 = Sprite::create("Blue_Front1.png");
    newSprite00->setPosition(100.f, 256.f);
    newSprite00->setName("sprite9") ;
    newSprite00->setAnchorPoint(Vec2(0.0f, 0.0f));
    scene->addChild(newSprite00);
    Sprite *point00 = Sprite::create("dot.png");
    point00->setName("point00");
    point00->setPosition(newSprite00->getPosition());
    scene->addChild(point00);
    
    Sprite *newSprite01 = Sprite::create("Blue_Front1.png");
    newSprite01->setPosition(250.f, 256.f);
    newSprite01->setName("sprite10") ;
    newSprite01->setAnchorPoint(Vec2(0.0f, 1.0f));
    scene->addChild(newSprite01);
    Sprite *point01 = Sprite::create("dot.png");
    point01->setName("point01");
    point01->setPosition(newSprite01->getPosition());
    scene->addChild(point01);
    
    Sprite *newSprite10 = Sprite::create("Blue_Front1.png");
    newSprite10->setPosition(400.f, 256.f);
    newSprite10->setName("sprite11") ;
    newSprite10->setAnchorPoint(Vec2(1.0f, 0.0f));
    scene->addChild(newSprite10);
    Sprite *point10 = Sprite::create("dot.png");
    point10->setName("point10");
    point10->setPosition(newSprite10->getPosition());
    scene->addChild(point10);
    
    Sprite *newSprite11 = Sprite::create("Blue_Front1.png");
    newSprite11->setPosition(550.f, 256.f);
    newSprite11->setName("sprite12") ;
    newSprite11->setAnchorPoint(Vec2(1.0f, 1.0f));
    scene->addChild(newSprite11);
    Sprite *point11 = Sprite::create("dot.png");
    point11->setName("point11");
    point11->setPosition(newSprite11->getPosition());
    scene->addChild(point11);
    
    Sprite *newSprite22 = Sprite::create("Blue_Front1.png");
    newSprite22->setPosition(700.f, 256.f);
    newSprite22->setName("sprite13") ;
    newSprite22->setAnchorPoint(Vec2(0.5f, 0.5f));
    scene->addChild(newSprite22);
    Sprite *point22 = Sprite::create("dot.png");
    point22->setName("point22");
    point22->setPosition(newSprite22->getPosition());
    scene->addChild(point22);
    
    menuItem->setString(Step7MenuLabel);
}

static void DoStep7SpriteMemu(Scene* scene, MenuItemFont* menuItem)
{
    scene->removeChildByName("sprite9");
    scene->removeChildByName("sprite10");
    scene->removeChildByName("sprite11");
    scene->removeChildByName("sprite12");
    scene->removeChildByName("sprite13");
    scene->removeChildByName("point00");
    scene->removeChildByName("point01");
    scene->removeChildByName("point10");
    scene->removeChildByName("point11");
    scene->removeChildByName("point22");
    
    Sprite *newSprite = Sprite::create("Blue_Front1.png");
    newSprite->setPosition(100.f, 256.f);
    newSprite->setName("sprite14");
    newSprite->setAnchorPoint(Vec2(0.5f, 0.5f));
    scene->addChild(newSprite);
    Sprite *point = Sprite::create("dot.png");
    point->setName("point1");
    point->setPosition(newSprite->getPosition());
    scene->addChild(point);
    
    Sprite *newSpriteSkewY = Sprite::create("Blue_Front1.png");
    newSpriteSkewY->setPosition(250.f, 256.f);
    newSpriteSkewY->setName("sprite15");
    newSpriteSkewY->setAnchorPoint(Vec2(0.5f, 0.5f));
    newSpriteSkewY->setSkewY(20.0f);
    scene->addChild(newSpriteSkewY);
    Sprite *pointY = Sprite::create("dot.png");
    pointY->setName("point2");
    pointY->setPosition(newSpriteSkewY->getPosition());
    scene->addChild(pointY);
    
    Sprite *newSpriteSkewX = Sprite::create("Blue_Front1.png");
    newSpriteSkewX->setPosition(400.f, 256.f);
    newSpriteSkewX->setName("sprite16");
    newSpriteSkewX->setAnchorPoint(Vec2(0.5f, 0.5f));
    newSpriteSkewX->setSkewX(20.0f);
    scene->addChild(newSpriteSkewX);
    Sprite *pointX = Sprite::create("dot.png");
    pointX->setName("point3");
    pointX->setPosition(newSpriteSkewX->getPosition());
    scene->addChild(pointX);
    
    menuItem->setString(Step8MenuLabel);
}

static void DoStep8SpriteMemu(Scene* scene, MenuItemFont* menuItem)
{
	scene->removeChildByName("sprite14");
	scene->removeChildByName("sprite15");
	scene->removeChildByName("sprite16");
	scene->removeChildByName("point1");
	scene->removeChildByName("point2");
	scene->removeChildByName("point3");

	Sprite *newSprite = Sprite::create("Blue_Front1.png");
	newSprite->setPosition(100, 256);
	newSprite->setName("sprite17");
	newSprite->setAnchorPoint(Vec2(0.5, 0.5));
	scene->addChild(newSprite, 1);
	Sprite* point00 = Sprite::create("dot.png");
	point00->setName("point00");
	point00->setPosition(newSprite->getPosition());
	scene->addChild(point00, 2);

	Sprite *newSpriteRotateP60 = Sprite::create("Blue_Front1.png");
	newSpriteRotateP60->setPosition(250, 256);
	newSpriteRotateP60->setName("sprite18");
	newSpriteRotateP60->setAnchorPoint(Vec2(0.5, 0.5));
	newSpriteRotateP60->setRotation(60.f);
	scene->addChild(newSpriteRotateP60, 1);
	Sprite* point01 = Sprite::create("dot.png");
	point01->setName("point01");
	point01->setPosition(newSpriteRotateP60->getPosition());
	scene->addChild(point01, 2);

	Sprite *newSpriteRotateN60 = Sprite::create("Blue_Front1.png");
	newSpriteRotateN60->setPosition(400, 256);
	newSpriteRotateN60->setName("sprite19");
	newSpriteRotateN60->setAnchorPoint(Vec2(0.5, 0.5));
	newSpriteRotateN60->setRotation(-60.f);
	scene->addChild(newSpriteRotateN60, 1);
	Sprite* point02 = Sprite::create("dot.png");
	point02->setName("point02");
	point02->setPosition(newSpriteRotateN60->getPosition());
	scene->addChild(point02, 2);

	Sprite *newSpriteRotateP240 = Sprite::create("Blue_Front1.png");
	newSpriteRotateP240->setPosition(550, 256);
	newSpriteRotateP240->setName("sprite20");
	newSpriteRotateP240->setAnchorPoint(Vec2(0.5, 0.5));
	newSpriteRotateP240->setRotation(240.f);
	scene->addChild(newSpriteRotateP240, 1);
	Sprite* point03 = Sprite::create("dot.png");
	point03->setName("point03");
	point03->setPosition(newSpriteRotateP240->getPosition());
	scene->addChild(point03, 2);

	Sprite *newSpriteRotateN240 = Sprite::create("Blue_Front1.png");
	newSpriteRotateN240->setPosition(700, 256);
	newSpriteRotateN240->setName("sprite21");
	newSpriteRotateN240->setAnchorPoint(Vec2(0.5, 0.5));
	newSpriteRotateN240->setRotation(-240.f);
	scene->addChild(newSpriteRotateN240, 1);
	Sprite* point04 = Sprite::create("dot.png");
	point04->setName("point04");
	point04->setPosition(newSpriteRotateN240->getPosition());
	scene->addChild(point04, 2);

	menuItem->setString(Step9MenuLabel);
}

static void DoStep9SpriteMemu(Scene* scene, MenuItemFont* menuItem)
{
	scene->removeChildByName("sprite17");
	scene->removeChildByName("sprite18");
	scene->removeChildByName("sprite19");
	scene->removeChildByName("sprite20");
	scene->removeChildByName("sprite21");
	scene->removeChildByName("point00");
	scene->removeChildByName("point01");
	scene->removeChildByName("point02");
	scene->removeChildByName("point03");
	scene->removeChildByName("point04");

	Sprite* newSprite = Sprite::create("Blue_Front1.png");
	newSprite->setPosition(100, 256);
	newSprite->setName("sprite21");
	newSprite->setAnchorPoint(Vec2(0.5f, 0.5f));
	scene->addChild(newSprite, 1);

	Sprite* newSprite2 = Sprite::create("Blue_Front1.png");
	newSprite2->setPosition(250, 256);
	newSprite2->setName("sprite22");
	newSprite2->setAnchorPoint(Vec2(0.5f, 0.5f));
	newSprite2->setColor(Color3B(155, 0, 0));
	scene->addChild(newSprite2, 1);

	Sprite* newSprite3 = Sprite::create("Blue_Front1.png");
	newSprite3->setPosition(400, 256);
	newSprite3->setName("sprite23");
	newSprite3->setAnchorPoint(Vec2(0.5f, 0.5f));
	newSprite3->setColor(Color3B(0, 200, 0));
	scene->addChild(newSprite3, 1);

	Sprite* newSprite4 = Sprite::create("Blue_Front1.png");
	newSprite4->setPosition(550, 256);
	newSprite4->setName("sprite24");
	newSprite4->setAnchorPoint(Vec2(0.5f, 0.5f));
	newSprite4->setColor(Color3B(0, 0, 50));
	scene->addChild(newSprite4, 1);

	menuItem->setString(Step10MenuLabel);
}

static void DoStep10SpriteMemu(Scene* scene, MenuItemFont* menuItem)
{
	scene->removeChildByName("sprite21");
	scene->removeChildByName("sprite22");
	scene->removeChildByName("sprite23");
	scene->removeChildByName("sprite24");

	Sprite* newSprite = Sprite::create("Blue_Front1.png");
	newSprite->setPosition(100, 256);
	newSprite->setName("sprite25");
	newSprite->setAnchorPoint(Vec2(0.5, 0.5));
	newSprite->setOpacity(0.0f);
	scene->addChild(newSprite, 1);

	Sprite* newSprite2 = Sprite::create("Blue_Front1.png");
	newSprite2->setPosition(250, 256);
	newSprite2->setName("sprite26");
	newSprite2->setAnchorPoint(Vec2(0.5, 0.5));
	newSprite2->setOpacity(30.0f);
	scene->addChild(newSprite2, 1);

	Sprite* newSprite3 = Sprite::create("Blue_Front1.png");
	newSprite3->setPosition(400, 256);
	newSprite3->setName("sprite27");
	newSprite3->setAnchorPoint(Vec2(0.5, 0.5));
	newSprite3->setOpacity(60.0f);
	scene->addChild(newSprite3, 1);

	Sprite* newSprite4 = Sprite::create("Blue_Front1.png");
	newSprite4->setPosition(550, 256);
	newSprite4->setName("sprite28");
	newSprite4->setAnchorPoint(Vec2(0.5, 0.5));
	newSprite4->setOpacity(90.0f);
	scene->addChild(newSprite4, 1);

	Sprite* newSprite5 = Sprite::create("Blue_Front1.png");
	newSprite5->setPosition(700, 256);
	newSprite5->setName("sprite29");
	newSprite5->setAnchorPoint(Vec2(0.5, 0.5));
	newSprite5->setOpacity(120.0f);
	scene->addChild(newSprite5, 1);

	Sprite* newSprite6 = Sprite::create("Blue_Front1.png");
	newSprite6->setPosition(850, 256);
	newSprite6->setName("sprite30");
	newSprite6->setAnchorPoint(Vec2(0.5, 0.5));
	newSprite6->setOpacity(150.0f);
	scene->addChild(newSprite6, 1);
	menuItem->setString(FinalMenuLabel);
}


static void DoFinalSpriteMemu(Scene* scene, MenuItemFont* menuItem)
{
	scene->removeChildByName("sprite25");
	scene->removeChildByName("sprite26");
	scene->removeChildByName("sprite27");
	scene->removeChildByName("sprite28");
	scene->removeChildByName("sprite29");
	scene->removeChildByName("sprite30");

	menuItem->setString(FirstMenuLabel);
}