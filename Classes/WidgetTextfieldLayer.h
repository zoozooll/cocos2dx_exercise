#ifndef __Widget_TEXTFIELD_Layer_H__
#define __Widget_TEXTFIELD_Layer_H__

#include <stdio.h>
#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class WidgetTextfieldLayer : public Layer
{
public:
	WidgetTextfieldLayer();
	~WidgetTextfieldLayer();

	virtual bool init();
	CREATE_FUNC(WidgetTextfieldLayer);
};

#endif