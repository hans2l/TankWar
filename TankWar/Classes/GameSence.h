//
//  GameSence.h
//  TankWar
//
//  Created by user on 13-9-3.
//
//

#ifndef __TankWar__GameSence__
#define __TankWar__GameSence__

#include <iostream>
#include "cocos2d.h"

#include "MapLayer.h"
#include "ControlLayer.h"

class GameScene : public cocos2d::CCScene
{
public:
    CREATE_FUNC(GameScene);
    ~GameScene();
    
    bool init();
private:
    MapLayer *_mapLayer;
    ControlLayer *_conLayer;
};

#endif /* defined(__TankWar__GameSence__) */
