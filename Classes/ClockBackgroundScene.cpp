
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
	static int mRotation = nMinute * 6;  //�����ʼ�Ƕ�
	static int sRotation = nSecond * 6;  //�����ʼ�Ƕ�

	static int hRotatio = (nHour % 12) * 30;            /*Сʱ�ļ�����ͬ�ڷֺ��룬�ֺ���һ�����ڶ���60����Сʱ����һ��֮���Ǵ�1-24��������Ҫ����ȡ����ʱ����ת��
									��12ʱ�ƣ��ٽ��䰴�ձ������60Ϊ���ڵ�����������ǰСʱ*5 */
	

	m_secondHand->setRotation(sRotation);  //�������������λ�ã�����Ƕ�˳ʱ����ת6�ȣ�����һ����
	m_minuteHand->setRotation(mRotation);  //���÷���λ��
	m_hourHand->setRotation(hRotatio);     //����ʱ��λ��
	if (sRotation >= 360){                //����������һȦ��360�ȣ�ʱ
		sRotation = 0;                   //������ת�ǹ���
		mRotation += 6;                  //����ת6�ȣ�������һ����
		m_minuteHand->setRotation(mRotation); //���÷���ָ��λ��
		if (mRotation % 72 == 0){                 //ÿ������ת��72�ı���ʱ
			hRotatio += 6;                     //ʱ��ת����
			m_hourHand->setRotation(hRotatio);   //����ʱ��λ��
			if (mRotation >= 360){              //������ת��һȦʱ
				mRotation = 0;                 //������ת�ǹ���
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
