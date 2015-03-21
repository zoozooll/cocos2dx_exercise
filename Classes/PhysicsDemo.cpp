#include "PhysicsDemo.h"

static const int DRAG_BODYS_TAG = 0x80;
static const int STATIC_SPRITE_TAG = 10;
static const int MAX_MULTI_RAYCAST_NUM = 5;

PhysicsDemo::PhysicsDemo()
{
}


PhysicsDemo::~PhysicsDemo()
{
}

bool PhysicsDemo::onTouchBegan(Touch* touch, Event* event)
{
	Vec2  location = touch->getLocation();
	Scene* scene = Director::getInstance()->getRunningScene();
	Vector<PhysicsShape*> arr = scene->getPhysicsWorld()->getShapes(location);
	PhysicsBody* body = nullptr;
	for (PhysicsShape* obj : arr)
	{
		if ((obj->getBody()->getTag() & DRAG_BODYS_TAG) != 0)
		{
			body = obj->getBody();
			break;
		}
	}
	if (body != nullptr)
	{
		Node* mouse = Node::create();
		mouse->setPhysicsBody(PhysicsBody::create(PHYSICS_INFINITY, PHYSICS_INFINITY));
		mouse->getPhysicsBody()->setDynamic(false);
		mouse->setPosition(location);
		addChild(mouse);
		PhysicsJointPin* joint = PhysicsJointPin::construct(mouse->getPhysicsBody(), body, location);
		joint->setMaxForce(5000.0F * body->getMass());
		scene->getPhysicsWorld()->addJoint(joint);
		_mouses.insert(make_pair(touch->getID(), mouse));
		return true;
	}
	return false;
}

void PhysicsDemo::onTouchMoved(Touch* touch, Event* event)
{
	unordered_map<int, Node*>::iterator it = _mouses.find(touch->getID());
	if (it != _mouses.end())
	{
		it->second->setPosition(touch->getLocation());
	}
}

void PhysicsDemo::onTouchEnded(Touch* touch, Event* event)
{
	unordered_map<int, Node*>::iterator it = _mouses.find(touch->getID());
	if (it != _mouses.end())
	{
		this->removeChild(it->second);
		_mouses.erase(it);
	}
}

bool PhysicsDemo::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Director* dir = Director::getInstance();
	dir->getRunningScene()
		->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	s_visibleSize = dir->getVisibleSize();
	s_origin = dir->getVisibleOrigin();
	s_center = s_origin + s_visibleSize / 2;

	TTFConfig ttfConfig("fonts/arial.ttf", 32);
	Label* titleLabel = Label::createWithTTF(ttfConfig, "Physics Chapter Samples");
	addChild(titleLabel, 4);
	titleLabel->setPosition(Vec2(s_origin.x + s_visibleSize.width / 2, s_origin.y + s_visibleSize.height - 30));
	string strSubTitle = subtitle();
	if (!strSubTitle.empty())
	{
		ttfConfig.fontSize = 20;
		Label* subTitleLabel = Label::createWithTTF(ttfConfig, strSubTitle.c_str());
		addChild(subTitleLabel, 4);
		subTitleLabel->setPosition(Vec2(s_origin.x + s_visibleSize.width * 0.5f, s_origin.y + s_visibleSize.height - 70));

	}

	/*MenuItemImage* backItem = MenuItemImage::create("leftNormal.png", "leftSelected.png",
		CC_CALLBACK_1(backMenuCallback, this)
		);

	MenuItemImage* restartItem = MenuItemImage::create("restartNormal.png", "restartSelected.png",
		CC_CALLBACK_1(restartMenuCallback, this)
		);

	MenuItemImage* nextItem = MenuItemImage::create("rightNormal.png", "rightSelected.png",
		CC_CALLBACK_1(nextMenuCallback, this)
		);

	Menu* menu = Menu::create(backItem, restartItem, nextItem, nullptr);
	menu->setPosition(Vec2::ZERO);
	addChild(menu, 4);

	Size restartItemSize = restartItem->getContentSize();
	backItem->setPosition(s_center.x - restartItemSize.width * 2, s_origin.y + restartItemSize.height / 2);
	restartItem->setPosition(s_center.x, s_origin.y + restartItemSize.height / 2);
	nextItem->setPosition(s_center.x + restartItemSize.width * 2, s_origin.y + restartItemSize.height / 2);*/

	Node* node = Node::create();
	PhysicsBody* physicsBody = PhysicsBody::createEdgeBox(s_visibleSize, PhysicsMaterial(0.1f, 1.0f, 0.0f));
	node->setPhysicsBody(physicsBody);
	node->setPosition(s_center);
	this->addChild(node);

	EventListenerTouchOneByOne* touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(PhysicsDemo::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(PhysicsDemo::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(PhysicsDemo::onTouchEnded, this);
	touchListener->onTouchCancelled = CC_CALLBACK_2(PhysicsDemo::onTouchCancelled, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
	return true;
}

Sprite* PhysicsDemo::addSpriteAtPosition(const Vec2& pos, int spriteIndex , float scale)
{
	string spritestrs[] = { "blueSprite.png", "whiteSprite.png", "LightBlueSprite.png" };
	Sprite* sprite = Sprite::create(spritestrs[spriteIndex]);
	PhysicsBody* physicsBody = PhysicsBody::createBox(Size(65.f * scale, 81.f * scale), PhysicsMaterial(0.1f, 1.0f, 0.0f));
	physicsBody->setTag(DRAG_BODYS_TAG);
	sprite->setScale(scale);
	sprite->setPosition(pos);
	sprite->setPhysicsBody(physicsBody);
	addChild(sprite);
	return sprite;
}

//void PhysicsDemo::nextMenuCallback(Ref* ref)
//{
//	nextCallback();
//}
//void PhysicsDemo::backMenuCallback(Ref* ref)
//{
//	backCallback();
//}
//void PhysicsDemo::restartMenuCallback(Ref* ref)
//{
//	restartCallback();
//}

bool PhysicsCorrelationToSprite::init()
{
	if (!PhysicsDemo::init())
	{
		return false;
	}
	Scene* scene = Director::getInstance()->getRunningScene();

	//Create the physics body.
	PhysicsBody* physicsBody = PhysicsBody::createBox(Size(65.f, 81.f));
	PhysicsMaterial(0.1f, 1.0f, 0.0f);
	physicsBody->setDynamic(false);
	
	//Add a Sprite at center.
	Sprite* sprite = Sprite::create("whiteSprite.png");
	sprite->setPosition(s_center);
	sprite->setPhysicsBody(physicsBody);
	addChild(sprite);

	//Add five sprites with dynamic body;
	for (int i = 0; i < 5; i++)
	{
		physicsBody = PhysicsBody::createBox(Size(65.0f, 81.0f));
		PhysicsMaterial(0.1f, 1.0f, 0.0f);
		physicsBody->setGravityEnable(false);
		physicsBody->setVelocity(Vec2(random(-500, 500), random(-500, 500)));
		physicsBody->setTag(DRAG_BODYS_TAG);
		sprite = Sprite::create("blueSprite.png");
		sprite->setPosition(Vec2(s_center.x + random(-300, 300), s_center.y + random(-300, 300)));
		sprite->setPhysicsBody(physicsBody);
		addChild(sprite);
	}
	return true;
}

string PhysicsCorrelationToSprite::subtitle() const
{
	return "Make body correlation to sprite.Please drag the sprites.";
}

bool PhysicsCollisionFiltering::init()
{
	if (!PhysicsDemo::init())
	{
		return false;
	}
	Sprite* sprite = addSpriteAtPosition(Vec2(s_center.x - 150, s_center.y));
	sprite->getPhysicsBody()->setCategoryBitmask(0x02);
	sprite->getPhysicsBody()->setCollisionBitmask(0x01);
	
	sprite = addSpriteAtPosition(Vec2(s_center.x - 150, s_center.y + 100));
	sprite->getPhysicsBody()->setCategoryBitmask(0x02);
	sprite->getPhysicsBody()->setCollisionBitmask(0x01);

	sprite = addSpriteAtPosition(Vec2(s_center.x + 150, s_center.y), 1);
	sprite->getPhysicsBody()->setCategoryBitmask(0x02);
	sprite->getPhysicsBody()->setCollisionBitmask(0x01);

	sprite = addSpriteAtPosition(Vec2(s_center.x + 150, s_center.y + 100), 2);
	sprite->getPhysicsBody()->setCategoryBitmask(0x02);
	sprite->getPhysicsBody()->setCollisionBitmask(0x01);
	return true;
}

string PhysicsCollisionFiltering::subtitle() const
{
	return "Collision Filtering.Please drag the sprites";
}

bool PhysicsCollisionProcessing::init()
{
	if (!PhysicsDemo::init())
	{
		return false;
	}
	Sprite* sprite = addSpriteAtPosition(s_center, 1);
	sprite->setTag(STATIC_SPRITE_TAG);
	sprite->getPhysicsBody()->setContactTestBitmask(0xffffffff);
	sprite->getPhysicsBody()->setDynamic(false);

	EventListenerPhysicsContact* contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(PhysicsCollisionProcessing::onContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
	schedule(CC_SCHEDULE_SELECTOR(PhysicsCollisionProcessing::tick), 0.3f);
	return true;
}

string PhysicsCollisionProcessing::subtitle() const
{
	return "Physics Collision Processing";
}

bool PhysicsCollisionProcessing::onContactBegin(PhysicsContact& contact)
{
	Node* nodeA = contact.getShapeA()->getBody()->getNode();
	Node* nodeB = contact.getShapeB()->getBody()->getNode();
	if (nodeA && nodeB)
	{
		if (nodeA->getTag() == STATIC_SPRITE_TAG)
		{
			nodeB->removeFromParentAndCleanup(true);
		}
		if (nodeB->getTag() == STATIC_SPRITE_TAG)
		{
			nodeA->removeFromParentAndCleanup(true);
		}
	}
	return true;
}

void PhysicsCollisionProcessing::tick(float dt)
{
	Sprite* sprite = addSpriteAtPosition(Vec2(s_center.x + random(-300, 300), s_center.y + random(-300, 300)));
	PhysicsBody* physicsBody = sprite->getPhysicsBody();
	physicsBody->setVelocity(Vec2(random(-500, 500), random(-500, 500)));
	physicsBody->setContactTestBitmask(0xffffffff);
}

bool PhysicsRayTest::init()
{
	if (!PhysicsDemo::init())
	{
		return false;
	}
	_angle = 0.0f;
	_drawNode = nullptr;
	EventListenerTouchAllAtOnce* touchListener = EventListenerTouchAllAtOnce::create();
	touchListener->onTouchesEnded = [&](const vector<Touch*>& touches, Event* event)
	{
		for (auto& touch : touches)
		{
			Sprite* sprite = addSpriteAtPosition(touch->getLocation());
			sprite->getPhysicsBody()->setGravityEnable(false);
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
	schedule(CC_SCHEDULE_SELECTOR(PhysicsRayTest::tick), 0.3f);
	return true;
}

string PhysicsRayTest::subtitle() const
{
	return "Ray test.";
}

void PhysicsRayTest::tick(float dt)
{
	Vec2 d(300 * cosf(_angle), 300 * sinf(_angle));
	Vec2 point2 = s_center + d;
	if (_drawNode)
	{
		removeChild(_drawNode);
	}
	_drawNode = DrawNode::create();

	Vec2 points[MAX_MULTI_RAYCAST_NUM];
	int num = 0;
	PhysicsRayCastCallbackFunc func = [&points, &num](PhysicsWorld& world, const PhysicsRayCastInfo& info, void* data) ->bool
	{
		if (num < MAX_MULTI_RAYCAST_NUM)
		{
			points[num++] = info.contact;
		}
		return true;
	};
	Director::getInstance()->getRunningScene()->getPhysicsWorld()->rayCast(func, s_center, point2, nullptr);
	_drawNode->drawSegment(s_center, point2, 1, Color4F::RED);
	for (int i = 0; i < num; i++)
	{
		_drawNode->drawDot(points[i], 2, Color4F(1.0f, 1.0f, 1.0f, 1.0f));

	}
	addChild(_drawNode);
	_angle += 1.5f * M_PI / 180.F;
}

bool PhysicsJointsDistance::init()
{
	if (!PhysicsDemo::init())
	{
		return false;
	}
	Sprite* sprite1 = addSpriteAtPosition(Vec2(s_center.x - 100, s_center.y));
	Sprite* sprite2 = addSpriteAtPosition(Vec2(s_center.x + 100, s_center.y));
	PhysicsJointDistance* joint = PhysicsJointDistance::construct(sprite1->getPhysicsBody(),
		sprite2->getPhysicsBody(), Point::ZERO, Point::ZERO);
	Director::getInstance()->getRunningScene()->getPhysicsWorld()->addJoint(joint);
	return true;
}

string PhysicsJointsDistance::subtitle() const
{
	return "Joints Test";
}