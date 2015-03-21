#ifndef __Widget_LOADINGBAR_Layer_H__
#define __Widget_LOADINGBAR_Layer_H__

#include <stdio.h>
#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class WidgetLoadingbarLayer : public Layer
{
public:
	WidgetLoadingbarLayer();
	~WidgetLoadingbarLayer();

	virtual bool init();
	CREATE_FUNC(WidgetLoadingbarLayer);
};

#endif