#ifndef __Widget_BUTTON_Layer_H__
#define __Widget_BUTTON_Layer_H__

#include <stdio.h>
#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class WidgetButtonLayer : public Layer
{
public:
	WidgetButtonLayer();
	~WidgetButtonLayer();

	virtual bool init();
	CREATE_FUNC(WidgetButtonLayer);
};

#endif