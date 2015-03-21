#ifndef __Widget_TILEMAP_Layer_H__
#define __Widget_TILEMAP_Layer_H__

#include <stdio.h>
#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class WidgetTilemapLayer : public Layer
{
public:
	WidgetTilemapLayer();
	~WidgetTilemapLayer();

	virtual bool init();
	CREATE_FUNC(WidgetTilemapLayer);
};

#endif