//
//  EnemySprite.h
//  TankWar
//
//  Created by user on 13-9-7.
//
//

#ifndef __TankWar__EnemySprite__
#define __TankWar__EnemySprite__

#include <iostream>
#include "cocos2d.h"
#include "TankSprite.h"

USING_NS_CC;

class EnemySprite : public TankSprite{
public:
    CREATE_FUNC(EnemySprite);
    virtual ~EnemySprite(void);
    
    virtual bool init();
    static EnemySprite* initWithKind(int Kind);
    
    void stopTankAction();
    void removeSelfFromMap();
    void checkTank(CCSprite* buttle);
    
    void initAction();
    void doRandomAction();
    void KeepMove();
    void rodmoFire();
    TankSprite* _tank;
protected:
    int _score;
};
#endif /* defined(__TankWar__EnemySprite__) */
