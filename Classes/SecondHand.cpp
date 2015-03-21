#include "SecondHand.h"

bool SecondHand::init()
{
	return true;
}

Sprite* SecondHand::getSprite()
{
	return m_sprite;
}

void SecondHand::bindSprite(Sprite *sprite)
{
	m_sprite = sprite;
	m_sprite->setAnchorPoint(ccp(0.0f, 0.5f));
	m_sprite->setScale(0.2f);
	m_sprite->setRotation(-90.0f);
	this->addChild(m_sprite);
}

void SecondHand::MutUpdate()
{

}