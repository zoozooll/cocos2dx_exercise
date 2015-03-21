#ifndef __Widget_SLIDER_Layer_H__
#define __Widget_SLIDER_Layer_H__

#include <stdio.h>
#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class WidgetSliderLayer : public Layer
{
public:
	WidgetSliderLayer();
	~WidgetSliderLayer();

	virtual bool init();
	CREATE_FUNC(WidgetSliderLayer);
};

#endif