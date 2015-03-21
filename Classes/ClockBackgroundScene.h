#ifndef __CLOCK_BACKGROUND_SCENE_H__
#define __CLOCK_BACKGROUND_SCENE_H__

#include <stdio.h>
#include <iostream>

#include "cocos2d.h"
#include "HourHand.h"
#include "MinuteHand.h"
#include "SecondHand.h"

USING_NS_CC;


class ClockBackgroundScene :
	public Layer
{
public:
	ClockBackgroundScene();
	~ClockBackgroundScene();

	static Scene* createScene();
	virtual bool init();
	void onMenuCloseCallback(Ref* sender);
	void MutUpdate(float f);
	CREATE_FUNC(ClockBackgroundScene);

private:
	int nHour;
	int nMinute;
	int nSecond;

public:
	HourHand *m_hourHand;
	MinuteHand *m_minuteHand;
	SecondHand *m_secondHand;
};

#endif