//
//  TankSprite.h
//  TankWar
//
//  Created by user on 13-9-3.
//
//

#ifndef __TankWar__TankSprite__
#define __TankWar__TankSprite__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;

typedef enum {
    kBorn = 1,
    kPlusStarOne,
    kPlusStarTwo,
    kPlusStarThree
}TankKind;

typedef enum {
    kUp = 1,
    kDown,
    kLeft,
    kRight,
    kFire,
    kStay,
    kPause
}TankAction;

class MapLayer;

class TankSprite : public cocos2d::CCSprite{
public:
    CREATE_FUNC(TankSprite);
    virtual ~TankSprite(void);
    
    virtual bool init();
    
    /**
     *	@brief	使用传入的参数初始化tank属性
     *
     *	@param 	numLife 	tank生命值
     *	@param 	tKind 	tank类型
     *	@param 	mSize 	tank所在地图大小
     *
     *	@return	初始化后的tank
     */
    static TankSprite* initWithDelegate(int numLife, int tKind, cocos2d::CCSize mSize);
    
    /**
     *	@brief	tank向上移动
     */
    void moveUp();

    /**
     *	@brief	tank向下移动
     */
    void moveDown();

    /**
     *	@brief	tank向左移动
     */
    void moveLeft();

    /**
     *	@brief	tank向右移动
     */
    void moveRight();

    /**
     *	@brief	检测tank移动后的坐标是否合法
     *
     *	@param 	pon 	tank移动后的坐标
     *
     *	@return	坐标是否合法
     */
    bool checkPoint(CCPoint pon);
    
    void onFire(void);
    
    void fire(CCSprite *buttle, TankAction buttleOrientation);
    
    void makeCanFire(void);
    
    //CC_SYNTHESIZE(MapLayer*, _mapLayer, MapLayer);
    //CC_SYNTHESIZE(CCTMXTiledMap*, _map, Map);
    MapLayer* _mapLayer;
    CCTMXTiledMap* _map;
protected:
    // tank移动速度
    int _speed;
    // tank生命值
    int _life;
    // 地图大小
    cocos2d::CCSize _mapSize;
    // tank类型
    TankKind _kind;
    // tank移动方向
    TankAction _kAction;
    //  tank能否发射子弹
    bool _isCanFire;
    // 子弹方向
    int _buttleOrientaion;
};
#endif /* defined(__TankWar__TankSprite__) */
