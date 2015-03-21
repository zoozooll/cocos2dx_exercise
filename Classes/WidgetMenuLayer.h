#ifndef __Widget_MENU_Layer_H__
#define __Widget_MENU_Layer_H__

#include <stdio.h>
#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class WidgetMenuLayer : public Layer
{
public:
	WidgetMenuLayer();
	~WidgetMenuLayer();

	virtual bool init();
	CREATE_FUNC(WidgetMenuLayer);
};

#endif