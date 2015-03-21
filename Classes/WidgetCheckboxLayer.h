#ifndef __Widget_CHECKBOX_Layer_H__
#define __Widget_CHECKBOX_Layer_H__

#include <stdio.h>
#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class WidgetCheckboxLayer : public Layer
{
public:
	WidgetCheckboxLayer();
	~WidgetCheckboxLayer();

	virtual bool init();
	CREATE_FUNC(WidgetCheckboxLayer);
};

#endif