#ifndef __HOUR_HAND__
#define __HOUR_HAND__

#include "cocos2d.h"

USING_NS_CC;

class HourHand : public Layer
{
public:
	HourHand();
	~HourHand();
	virtual bool init();
	Sprite* getSprite();
	void bindSprite(Sprite* sprite);
	CREATE_FUNC(HourHand);
	
private:
	Sprite *m_sprite;
};

#endif
