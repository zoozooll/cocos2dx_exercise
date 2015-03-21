#ifndef __Physics_DEMO_H__
#define __Physics_DEMO_H__

#include <stdio.h>
#include <iostream>
#include "cocos2d.h"

using namespace std;
USING_NS_CC;

class PhysicsDemo : public cocos2d::Layer
{
public:
	PhysicsDemo();
	~PhysicsDemo();

	virtual string subtitle() const 
	{
		return "";
	}

	/*void setRestartCallback(function<void(void)> callback)
	{
		this->restartCallback = callback;
	}
	void setNextCallback(function<void(void)> callback)
	{
		this->nextCallback = callback;
	}
	void setBackCallback(function<void(void)> callback)
	{
		this->backCallback = callback;
	}*/

	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);

protected:
	virtual bool init();
	Sprite* addSpriteAtPosition(const Vec2& pos, int spriteIndex = 0, float scale = 1.0f);
	unordered_map<int, Node*> _mouses;
	Size s_visibleSize;
	Vec2 s_origin;
	Vec2 s_center;

private:
	/*function<void(void)>  restartCallback;
	function<void(void)>  nextCallback;
	function<void(void)> backCallback;*/
	/*void nextMenuCallback(Ref*);
	void backMenuCallback(Ref*);
	void restartMenuCallback(Ref*);*/
};

class PhysicsCorrelationToSprite : public PhysicsDemo
{
public:
	virtual string subtitle() const override;
	CREATE_FUNC(PhysicsCorrelationToSprite);

protected:
	virtual bool init();
};


class PhysicsCollisionFiltering : public PhysicsDemo
{
public:
	virtual string subtitle() const override;
	CREATE_FUNC(PhysicsCollisionFiltering);

protected:
	virtual bool init();
};

class PhysicsCollisionProcessing : public PhysicsDemo
{
public:
	virtual string subtitle() const override;
	bool onContactBegin(PhysicsContact& contact);
	void tick(float dt);
	CREATE_FUNC(PhysicsCollisionProcessing);

protected:
	virtual bool init();
};

class PhysicsRayTest : public PhysicsDemo
{
public:
	virtual string subtitle() const override;
	void tick(float dt);
	CREATE_FUNC(PhysicsRayTest);

protected:
	virtual bool init();
	DrawNode* _drawNode;
	float _angle;
};

class PhysicsJointsDistance: public PhysicsDemo
{
public:
	virtual string subtitle() const override;
	CREATE_FUNC(PhysicsJointsDistance);

protected:
	virtual bool init();
};

#endif