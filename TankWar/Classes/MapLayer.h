//
//  MapLayer.h
//  TankWar
//
//  Created by user on 13-9-3.
//
//

#ifndef __TankWar__MapLayer__
#define __TankWar__MapLayer__

#include <iostream>
#include "cocos2d.h"

#include "TankSprite.h"

USING_NS_CC;

class MapLayer : public cocos2d::CCLayerColor
{
public:
    CREATE_FUNC(MapLayer);
    virtual ~MapLayer(void);
    
    bool init();
    
    /**
     *	@brief	使用传入的参数初始化地图层
     *
     *	@param 	leve 	游戏关数，依据该参数选择tmx地图
     *	@param 	tKind 	坦克类型
     *	@param 	numLife 	坦克生命值
     */
    void initWithMap(int leve, int tKind, int numLife);
    
    
    /**
     *	@brief	根据对象名从对象层获取对象的坐标
     *
     *	@param 	group 	对象层的所有对象
     *	@param 	object 	要获取的对象名字
     *
     *	@return	要获取的对象坐标
     */
    CCPoint objectPosition(CCTMXObjectGroup *group, const char *object);

private:
    int _leve;
    
    cocos2d::CCTMXLayer* _bg1Layer;
    //cocos2d::CCTMXLayer* _bg2Layer;
    
    cocos2d::CCTMXObjectGroup* _objects;
    CCSprite *_tank1;
    
};
#endif /* defined(__TankWar__MapLayer__) */
