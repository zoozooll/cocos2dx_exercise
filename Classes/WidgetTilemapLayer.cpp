#include "WidgetTilemapLayer.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

WidgetTilemapLayer::WidgetTilemapLayer()
{
}


WidgetTilemapLayer::~WidgetTilemapLayer()
{
}

bool WidgetTilemapLayer::init()
{
	Director* dire = Director::getInstance();
	Rect visibleRect = dire->getOpenGLView()->getVisibleRect();
	Size visibleSize = dire->getVisibleSize();
	Vec2 origin = dire->getVisibleOrigin();

	int index = 2;
	LabelTTF* label = LabelTTF::create("TileMap", "Marker Felt.ttf", 25);
	Vec2 showingBase = Vec2(visibleRect.origin.x + visibleRect.size.width * 0.5f, visibleRect.origin.y + visibleRect.size.height * 0.5f);
	label->setPosition(showingBase.x, showingBase.y - 30);
	addChild(label, 1);

	label = LabelTTF::create("MainMenu", "Marker Felt.ttf", 25);
	MenuItemLabel* menuItem = MenuItemLabel::create(label);
	menuItem->setCallback([&](cocos2d::Ref *sender) {
		this->setVisible(false);
		Scene* scene = Director::getInstance()->getRunningScene();
		Layer* rootLayer = (Layer*)scene->getChildByName("rootLayer");
		rootLayer->setVisible(true);

	});

	Menu* menu = Menu::create(menuItem, nullptr);
	menu->setPosition(Vec2::ZERO);
	menuItem->setPosition(Vec2(visibleRect.origin.x + visibleRect.size.width - 80, visibleRect.origin.y + 25));
	addChild(menu, 1);

	// This is for TileMap section of Programmers guide;

    TMXTiledMap* map = TMXTiledMap::create("isometric_grass_and_water.tmx");
	map->setPosition(Vec2(showingBase.x, showingBase.y - (index++) * 40));
    EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [](Touch* touch, Event* event)
    {
        
        return true;
    };
    listener->onTouchEnded = [=](Touch* touch, Event* event)
    {
        TMXLayer* layer = map->getLayer("layer0");
        Director* dir = Director::getInstance();
        Size viewSize = dir->getWinSize();
        Vec2 mapCordinate = map->convertToNodeSpace(dir->convertToGL(touch->getLocationInView()));
        int tileX = mapCordinate.x /map->getTileSize().width;
        int tileY = (viewSize.height - mapCordinate.y) / map->getTileSize().height;
        int id = layer->getTileGIDAt(Vec2(tileX, tileY));
        Sprite* tileSprite = layer->getTileAt(Vec2(tileX, tileY));
        CCLOG("Tile GID: %d", id);
                                
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, map);
	addChild(map, 2);
	return true;
}