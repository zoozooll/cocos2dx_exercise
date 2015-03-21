#ifndef __MINUTE_HAND_H__
#define __MINUTE_HAND_H__

#include "cocos2d.h"
USING_NS_CC;

class MinuteHand : public Layer
{
public:
	MinuteHand();
	~MinuteHand();
	virtual bool init();
	Sprite* getSprite();
	void bindSprite(Sprite* sprite);
	CREATE_FUNC(MinuteHand);

private:
	Sprite *m_sprite;
};

#endif
