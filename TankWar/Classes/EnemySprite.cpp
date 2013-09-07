//
//  EnemySprite.cpp
//  TankWar
//
//  Created by user on 13-9-7.
//
//

#include "EnemySprite.h"

#define FRAME(image) CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(image)

bool EnemySprite::init()
{
    bool bRet = false;
    do {
        CC_BREAK_IF(! TankSprite::init());
        
        // 自添加代码
        
        
        bRet = true;
    } while (0);
    return bRet;
}

EnemySprite* EnemySprite::initWithKind(int Kind)
{
    CCSpriteFrame* frame;
    EnemySprite* enemy;
    switch (Kind) {
        case kSlow:
            frame = FRAME("en1.png");
            enemy = (EnemySprite *)EnemySprite::createWithSpriteFrame(frame);
            enemy->_life = 1;
            enemy->_speed = 1;
            enemy->_score = 500;
            enemy->_eKind = kSlow;
            enemy->_enemyKindForScore = kSlow;
            enemy->setRotation(180);
            break;
        case kQuike:
            frame = FRAME("en2.png");
            enemy = (EnemySprite *)EnemySprite::createWithSpriteFrame(frame);
            
            enemy->_life = 1;
            enemy->_speed = 2;
            enemy->_score = 1000;
            enemy->_eKind = kQuike;
            enemy->_enemyKindForScore = kQuike;
            enemy->setRotation(180);
            break;
            
        case kStrong:
            frame = FRAME("en6.png");
            enemy = (EnemySprite *)EnemySprite::createWithSpriteFrame(frame);
            
            enemy->_life = 1;
            enemy->_speed = 1;
            enemy->_score = 1000;
            enemy->_eKind = kStrong;
            enemy->_enemyKindForScore = kStrong;
            enemy->setRotation(180);
            break;
            
        case kStrongYellow:
            frame = FRAME("en5.png");
            enemy = (EnemySprite *)EnemySprite::createWithSpriteFrame(frame);
            
            enemy->_life = 2;
            enemy->_speed = 1;
            enemy->_score = 1500;
            enemy->_eKind = kStrongYellow;
            enemy->_enemyKindForScore = kStrongYellow;
            enemy->setRotation(180);
            break;
            
        case kStrongRedLife3:
            frame = FRAME("en7.png");
            enemy = (EnemySprite *)EnemySprite::createWithSpriteFrame(frame);
            enemy->_life = 3;
            enemy->_speed = 1;
            enemy->_score = 2000;
            enemy->_isRead = true;
            enemy->_eKind = kStrongRedLife3;
            enemy->_enemyKindForScore = kStrongRedLife3;
            enemy->setRotation(180);
            break;
            
        case kStrongRed:
            frame = FRAME("en7.png");
            enemy = (EnemySprite *)EnemySprite::createWithSpriteFrame(frame);
            
            enemy->_life = 1;
            enemy->_speed = 1;
            enemy->_score = 2500;
            enemy->_eKind = kStrongRed;
            enemy->_enemyKindForScore = kStrongRed;
            enemy->_isRead = true;
            enemy->setRotation(180);
            break;
            
        case kStrongGreen:
            frame = FRAME("en3.png");
            enemy = (EnemySprite *)EnemySprite::createWithSpriteFrame(frame);
            enemy->_life = 3;
            enemy->_speed = 1;
            enemy->_score = 3000;
            enemy->_eKind = kStrongGreen;
            enemy->_enemyKindForScore = kStrongGreen;
            enemy->setRotation(180);
            break;
            
        case kQuikeR:
            frame = FRAME("en2r.png");
            enemy = (EnemySprite *)EnemySprite::createWithSpriteFrame(frame);
            enemy->_life = 1;
            enemy->_speed = 2;
            enemy->_score = 1000;
            enemy->_eKind = kQuikeR;
            enemy->_enemyKindForScore = kQuikeR;
            enemy->_isRead = true;
            enemy->setRotation(180);
            break;
            
        case kSlowR:
            frame = FRAME("en1r.png");
            enemy = (EnemySprite *)EnemySprite::createWithSpriteFrame(frame);
            enemy->_life = 1;
            enemy->_speed = 1;
            enemy->_score = 500;
            enemy->_isRead = true;
            enemy->setRotation(180);
            enemy->_eKind = kSlowR;
            enemy->_enemyKindForScore = kSlowR;
            break;
            
        default:
            break;
    }
    
    enemy->setScale(0.8f);
    enemy->_kAction = kDown;
    enemy->_isCanFire = true;
    //enemy->animationBorn();
    //[tank scheduleOnce:@selector(initAction) delay:1];
    return enemy;
}


void EnemySprite::stopTankAction()
{

}

void EnemySprite::removeSelfFromMap()
{

}

void EnemySprite::checkTank(CCSprite* buttle)
{
    
}