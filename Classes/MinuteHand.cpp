#include "MinuteHand.h"


MinuteHand::MinuteHand()
{
}


MinuteHand::~MinuteHand()
{
}

bool MinuteHand::init()
{
	return true;
}

Sprite* MinuteHand::getSprite()
{
	return this->m_sprite;
}

void MinuteHand::bindSprite(Sprite* sprite)
{
	m_sprite = sprite;
	m_sprite->setAnchorPoint(ccp(0.0f, 0.5f));
	m_sprite->setScale(0.2f);
	m_sprite->setRotation(-90.0f);
	addChild(m_sprite);
}
