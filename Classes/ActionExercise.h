#ifndef __ACTION_EXERCISE_H__
#define __ACTION_EXERCISE_H__

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class ActionExercise : public Layer
{
public:
	ActionExercise();
	~ActionExercise();

	static cocos2d::Scene* createScene();

	virtual bool init();

	void menuCloseCallback(cocos2d::Ref* pSender);

	void menuClickedCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(ActionExercise);
};

#endif
