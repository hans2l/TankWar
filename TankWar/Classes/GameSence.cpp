//
//  GameSence.cpp
//  TankWar
//
//  Created by user on 13-9-3.
//
//

#include "GameSence.h"

GameScene::~GameScene()
{}

bool GameScene::init()
{
    bool bRet = false;
    do {
        CC_BREAK_IF(! CCScene::init());
        
        // 自添加代码
        
        _mapLayer = MapLayer::create();
        _mapLayer->initWithMap(1, 1, 1);
        addChild(_mapLayer);
        
        bRet = true;
    } while (0);
    return bRet;
}


