//
//  TankSprite.cpp
//  TankWar
//
//  Created by user on 13-9-3.
//
//

#include "TankSprite.h"

bool TankSprite::init()
{
    bool bRet = false;
    do {
        CC_BREAK_IF( !CCSprite::init() );
        
        // 自添加代码
        
        
        bRet = true;
    } while (0);
    return bRet;
}

TankSprite* TankSprite::initWithDelegate(int numLife, int tKind, cocos2d::CCSize mSize)
{
    TankSprite *tank;
    
    switch (tKind) {
        case kBorn:
            tank = (TankSprite*)CCSprite::create("images/tank.png");
            tank->_speed = 1;
            break;
            
        case kPlusStarOne:
        case kPlusStarTwo:
        case kPlusStarThree:
            break;
            
        default:
            break;
    }
    
    tank->_life = numLife;
    tank->_mapSize = mSize;
    tank->_kind = (TankKind)tKind;
    tank->setScale(0.7);
    //  方向默认向上
    tank->_kAction = kUp;
    
    return tank;
}