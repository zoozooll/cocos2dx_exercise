#ifndef __WidgetsScene_H__
#define __WidgetsScene_H__

#include <stdio.h>
#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class WidgetsScene : public Layer
{
public:
	WidgetsScene();
	~WidgetsScene();
	
	static Scene* createScene();

	virtual bool init();
	
	void onMenuCloseCallback(Ref* sender);

	void menuClickedCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(WidgetsScene);

private:
	Scene* playingScene;

};

#endif
