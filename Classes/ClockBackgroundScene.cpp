
#include <stdio.h>
#include <iostream>

#include "ClockBackgroundScene.h"
#include "WidgetsScene.h"

ClockBackgroundScene::ClockBackgroundScene()
{
}


ClockBackgroundScene::~ClockBackgroundScene()
{
}


Scene* ClockBackgroundScene::createScene()
{
	ClockBackgroundScene *layer = ClockBackgroundScene::create();
	Scene *scene = Scene::create();
	scene->addChild(layer);
	return scene;
}

bool ClockBackgroundScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Node::init())
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
		CC_CALLBACK_1(ClockBackgroundScene::onMenuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	auto nextScene = MenuItemImage::create(
		"button1.png",
		"button2.png");

	nextScene->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + visibleSize.height - closeItem->getContentSize().height / 2));
	
	nextScene->setCallback([&](Ref* sender)
	{
		Director* dir = Director::getInstance();
		dir->replaceScene(WidgetsScene::createScene());
	});

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, nextScene, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	Size winSize = Director::sharedDirector()->getWinSize();
	Sprite *dials = Sprite::create("background.jpg");
	dials->setPosition(ccp(winSize.width / 2.0f, winSize.height / 2.0f));
	dials->setScale(0.5f);
	this->addChild(dials);

	m_hourHand = HourHand::create();
	m_hourHand->bindSprite(Sprite::create("shi.png"));
	m_hourHand->setPosition(ccp(winSize.width * 0.5f, winSize.height * 0.5f));
	addChild(m_hourHand);

	m_minuteHand = MinuteHand::create();
	m_minuteHand->bindSprite(Sprite::create("fen.png"));
	m_minuteHand->setPosition(ccp(winSize.width * 0.5f, winSize.height * 0.5f));
	addChild(m_minuteHand);

	m_secondHand = SecondHand::create();
	m_secondHand->bindSprite(Sprite::create("miao.png"));
	m_secondHand->setPosition(ccp(winSize.width * 0.5f, winSize.height * 0.5f));
	addChild(m_secondHand);

	struct timeval nowTimeval;
	gettimeofday(&nowTimeval, NULL);
	struct tm *tm;
	time_t time_sec;
	time_sec = nowTimeval.tv_sec;
	tm = localtime(&time_sec);
	nHour = tm->tm_hour;
	nMinute = tm->tm_min;
	nSecond = tm->tm_sec;
	//CCLog("%d:%d:%d", nHour, nMinute, nSecond);
	
	this->schedule(schedule_selector(ClockBackgroundScene::MutUpdate), 1.0f);

	return true;
}

void ClockBackgroundScene::MutUpdate(float f)
{
	static int mRotation = nMinute * 6;  //分针初始角度
	static int sRotation = nSecond * 6;  //秒针初始角度

	static int hRotatio = (nHour % 12) * 30;            /*小时的计数不同于分和秒，分和秒一个周期都是60，而小时数在一天之中是从1-24，我们需要将获取到的时间先转换
									成12时制，再将其按照比例变成60为周期的数，即给当前小时*5 */
	

	m_secondHand->setRotation(sRotation);  //重新设置秒针的位置，另其角度顺时针旋转6度，即走一秒钟
	m_minuteHand->setRotation(mRotation);  //重置分针位置
	m_hourHand->setRotation(hRotatio);     //重置时针位置
	if (sRotation >= 360){                //当秒针走了一圈（360度）时
		sRotation = 0;                   //秒针旋转角归零
		mRotation += 6;                  //分针转6度，即走了一分钟
		m_minuteHand->setRotation(mRotation); //重置分针指针位置
		if (mRotation % 72 == 0){                 //每当分针转到72的倍数时
			hRotatio += 6;                     //时针转六度
			m_hourHand->setRotation(hRotatio);   //重置时针位置
			if (mRotation >= 360){              //当分针转了一圈时
				mRotation = 0;                 //分针旋转角归零
			}
		}
	}
	sRotation += 6;

}

void ClockBackgroundScene::onMenuCloseCallback(Ref* sender)
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
