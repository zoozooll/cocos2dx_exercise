#ifndef __PHYSIC_SSCENE_H__
#define __PHYSIC_SSCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class PhysicsScene : public Layer
{
public:
	PhysicsScene();
	~PhysicsScene();

	static Scene* createScene();

	virtual bool init();

	void onMenuCloseCallback(Ref* sender);

	void next(Ref*);
	void restart(Ref*);
	void back(Ref*);

	CREATE_FUNC(PhysicsScene);

//private:
//	Map<int, Layer> physicsDemoLayMap;
};

#endif
