#ifndef __Widget_Label_Layer_H__
#define __Widget_Label_Layer_H__

#include <stdio.h>
#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class WidgetLabelLayer : public Layer
{
public:
	WidgetLabelLayer();
	~WidgetLabelLayer();

	virtual bool init();
	CREATE_FUNC(WidgetLabelLayer);
};

#endif