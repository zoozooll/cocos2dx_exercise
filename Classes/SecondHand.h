#ifndef __SECOND_HAND_H__
#define __SECOND_HAND_H__



#include "cocos2d.h"

USING_NS_CC;

class SecondHand :public Layer
{
private:
	Sprite *m_sprite;
public :
	virtual bool init();
	Sprite* getSprite();
	void bindSprite(Sprite *sprite);
	void MutUpdate();
	CREATE_FUNC(SecondHand);

};

#endif