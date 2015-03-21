#ifndef __Widget_PARRLLAX_Layer_H__
#define __Widget_PARRLLAX_Layer_H__

#include <stdio.h>
#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class WidgetParallaxLayer : public Layer
{
public:
	WidgetParallaxLayer();
	~WidgetParallaxLayer();

	virtual bool init();
	CREATE_FUNC(WidgetParallaxLayer);
};

#endif