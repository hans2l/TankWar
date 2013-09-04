//
//  MapLayer.cpp
//  TankWar
//
//  Created by user on 13-9-3.
//
//

#include "MapLayer.h"

MapLayer::~MapLayer(){}

bool MapLayer::init()
{
    bool bRet = false;
    do {
        // 屏幕的大小
        CCSize wSize = CCDirector::sharedDirector()->getVisibleSize();
        CCLOG("WindowSize: %f, %f", wSize.width,wSize.height);
        
        CC_BREAK_IF(! CCLayerColor::initWithColor(ccc4(0, 0, 0, 255), wSize.height, wSize.height));
        
        bRet = true;
    } while (0);
    return bRet;
}

void MapLayer::initWithMap(int leve, int tKind, int numLife)
{
    _leve = leve;
    
    // 解析tmx地图
    cocos2d::CCTMXTiledMap *map = cocos2d::CCTMXTiledMap::create(CCString::createWithFormat("maps/map%d.tmx",leve)->getCString());
    
    // 地图的大小
    CCSize cSize = map->getContentSize();
    CCLOG("ContentSize: %f, %f", cSize.width,cSize.height);
    
    // 屏幕的大小
    CCSize wSize = CCDirector::sharedDirector()->getVisibleSize();
    CCLOG("WindowSize: %f, %f", wSize.width,wSize.height);
    
    // 缩放比例
    float scale = wSize.height / cSize.height;
    map->setScale(scale);
    
    // 将地图向右平移屏幕宽度的1/6
    map->setPosition(wSize.width / 6, 0);
    CCLog("MapPosition: %f, %f", map->getPositionX(), map->getPositionY());
    
    addChild(map, 1);
    
    // 从地图中获取地图层
    _bg1Layer = map->layerNamed("bg1");
    
    // 从地图中获取对象层
    _objects = map->objectGroupNamed("objects");
    
    // 创建玩家坦克
    _tank1 = TankSprite::initWithDelegate(numLife, tKind, _bg1Layer->getContentSize());
    
    // 设置玩家坦克坐标
    CCPoint tankPoint = this->objectPosition(_objects, "pl1");
    _tank1->setPosition(ccp(tankPoint.x+map->getTileSize().width, tankPoint.y+map->getTileSize().width));
    
    map->addChild(_tank1, 1);
}

CCPoint MapLayer::objectPosition(CCTMXObjectGroup *group,const char *object)
{
    CCPoint point;
    CCDictionary *dic=group->objectNamed(object);
    point.x=dic->valueForKey("x")->intValue();
    point.y=dic->valueForKey("y")->intValue();
    return point;
}