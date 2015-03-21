#include "HourHand.h"


HourHand::HourHand()
{
}


HourHand::~HourHand()
{
}

bool HourHand::init()
{
	return true;
}

Sprite* HourHand::getSprite()
{
	return m_sprite;
}

void HourHand::bindSprite(Sprite* sprite)
{
	m_sprite = sprite;
	m_sprite->setAnchorPoint(ccp(0.0f, 0.5f));
	m_sprite->setScale(0.2f);
	m_sprite->setRotation(-90.0f);
	addChild(m_sprite);
}
