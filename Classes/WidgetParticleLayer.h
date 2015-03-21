#ifndef __Widget_PARTICLE_Layer_H__
#define __Widget_PARTICLE_Layer_H__

#include <stdio.h>
#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class WidgetParticleLayer : public Layer
{
public:
	WidgetParticleLayer();
	~WidgetParticleLayer();

	virtual bool init();
	CREATE_FUNC(WidgetParticleLayer);
};

#endif