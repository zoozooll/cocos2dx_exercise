#ifndef __CHARPTER_3_H__
#define __CHARPTER_3_H__

#include "cocos2d.h"

USING_NS_CC;

class Charpter3 :
	public Layer
{
public:
	Charpter3();
	~Charpter3();

	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(Charpter3);

private:
	Scene *rootScene;

};

#endif
