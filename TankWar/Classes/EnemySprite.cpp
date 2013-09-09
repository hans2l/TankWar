//
//  EnemySprite.cpp
//  TankWar
//
//  Created by user on 13-9-7.
//
//

#include "EnemySprite.h"
#include "MapLayer.h"

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
    // 敌方坦克出生动画
    //enemy->animationBorn();
    enemy->scheduleOnce(schedule_selector(EnemySprite::initAction), 1);
    return enemy;
}


void EnemySprite::stopTankAction()
{

}

void EnemySprite::removeSelfFromMap()
{

}

void EnemySprite::initAction()
{
    this->unschedule(schedule_selector(EnemySprite::initAction));
    this->schedule(schedule_selector(EnemySprite::doRandomAction), 1);
    this->schedule(schedule_selector(EnemySprite::KeepMove), 1/30);
    this->schedule(schedule_selector(EnemySprite::rodmoFire), 1);
}

void EnemySprite::doRandomAction()
{
    float ran = CCRANDOM_0_1();
    
    if (ran < 0.4) _kAction = kDown;
    else if (ran < 0.6) _kAction = kLeft;
    else if (ran < 0.9) _kAction = kRight;
    else _kAction = kUp;
}

void EnemySprite::KeepMove()
{
    switch (_kAction) {
        case kUp:
            this->moveUp();
            break;
        case kDown:
            this->moveDown();
            break;
        case kLeft:
            this->moveLeft();
            break;
        case kRight:
            this->moveRight();
            break;
        default:
            break;
    }
}

void EnemySprite::rodmoFire()
{
    int rodom;
    
    for (int i = 0; i < 4; i++) {
        rodom = arc4random() % 4;
        if (rodom == 0) {
            this->onFire();
        }else if (rodom == 1){
            this->unschedule(schedule_selector(EnemySprite::onFire));
            this->scheduleOnce(schedule_selector(EnemySprite::onFire), 0.2);
        }else if (rodom == 2){
            this->unschedule(schedule_selector(EnemySprite::onFire));
            this->scheduleOnce(schedule_selector(EnemySprite::onFire), 0.4);
        }else if (rodom == 3){
            this->unschedule(schedule_selector(EnemySprite::onFire));
            this->scheduleOnce(schedule_selector(EnemySprite::onFire), 0.7);
        }
    }
}

void EnemySprite::onFire()
{
    CCSpriteFrame* framButtle = FRAME("bullet.png");
    if (_isCanFire == false) return;
    _buttleOrientation = _kAction;
    CCSprite* buttle = CCSprite::spriteWithSpriteFrame(framButtle);
    
    _buttle = buttle;
    _map->addChild(buttle, -1);
    buttle->setVisible(false);
    _isCanFire = false;
    
    this->fire(buttle, _kAction);
}

void EnemySprite::fire(CCSprite *buttle, TankAction buttleOrientation)
{
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sounds/bullet.aif");
    
    CCPoint ptn;
    // 设置子弹的消失位置
    switch (buttleOrientation) {
        case kUp:
            
            buttle->setRotation(0);
            
            buttle->setPosition(ccp(this->getPosition().x, this->getPosition().y+this->boundingBox().size.height/2));
            
            //终点
            ptn=ccp(this->getPosition().x, this->getPosition().y+_mapSize.width);
            
            break;
        case kDown:
            
            buttle->setRotation(180);
            
            buttle->setPosition(ccp(this->getPosition().x, this->getPosition().y-this->boundingBox().size.height/2));
            
            
            ptn=ccp(this->getPosition().x, this->getPosition().y-_mapSize.width);
            
            break;
        case kRight:
            
            buttle->setRotation(90);
            
            buttle->setPosition(ccp(this->getPosition().x+this->boundingBox().size.width/2, this->getPosition().y));
            
            
            ptn=ccp(this->getPosition().x+_mapSize.width, this->getPosition().y);
            
            break;
        case kLeft:
            
            buttle->setRotation(-90);
            
            buttle->setPosition(ccp(this->getPosition().x-this->boundingBox().size.width/2, this->getPosition().y));
            
            
            ptn=ccp(this->getPosition().x-_mapSize.width, this->getPosition().y);
            
            break;
            
            
        default:
            break;
    }
    
    const CCPoint realyPosition = ptn;
    
    // 创建子弹移动动画
    // Show子弹
    CCShow *ac1=CCShow::create();
    // 子弹移动到边界
    CCMoveTo *ac2=CCMoveTo::create(2.0, realyPosition);
    // 组合子弹移出屏幕后的操作
    CCFiniteTimeAction *seq=CCSequence::create(ac1,ac2,CCCallFunc::create(this, callfunc_selector(EnemySprite::makeCanFire)),NULL);
    buttle->runAction(seq);
    
    this->schedule(schedule_selector(EnemySprite::checkBang), 1/60);
}

void EnemySprite::makeCanFire()
{
    _isCanFire = true;
}

void EnemySprite::checkBang()
{
    CCPoint btPoint = _buttle->getPosition();
    unsigned int gid = _mapLayer->tileIDFromPosition(btPoint);
    
    if(gid == -1
       || checkLayer2()
       || checkHome()
       || checkTank()
       || checkWall()
       || checkStrongWall()){
        // 停止tank的碰撞检测定时器
        this->unschedule(schedule_selector(EnemySprite::checkBang));
        // 从移除地图层移出buttle
        _buttle->removeFromParentAndCleanup(true);
        _isCanFire = true;
        _buttle = NULL;
        return;
    }
}

bool EnemySprite::checkTank()
{
    
    
    CCRect tankRect;
    
    //敌人tank才做这个检测 所以self值得是敌人tank
    
    if (_tank->isVisible() != false){
        
        tankRect = CCRectMake(_tank->getPosition().x - _tank->boundingBox().size.width/2,_tank->getPosition().y - _tank->boundingBox().size.height/2,_tank->boundingBox().size.width,_tank->boundingBox().size.height);

        if (tankRect.containsPoint(_buttle->getPosition())) {
            
            if (_tank->_isProtect) {
                return true;
            }else {
                //CCLog("Oh no!!!");
                CCSpriteFrame* newFrame;
                if (_tank->_kind == kPlusStarThree){
                    newFrame = CCSpriteFrameCache:: sharedSpriteFrameCache()-> spriteFrameByName("p1-b.png");
                    _tank->setDisplayFrame(newFrame);
                    _tank->_speed = 1.5;
                    _tank->_kind = kPlusStarTwo;
                    return true;
                }else if (_tank->_kind == kPlusStarTwo){
                    newFrame = CCSpriteFrameCache:: sharedSpriteFrameCache()-> spriteFrameByName("p1-a.png");
                    _tank->setDisplayFrame(newFrame);
                    _tank->_speed = 1.5;
                    _tank->_kind = kPlusStarOne;
                    return true;
                }else {
                    newFrame = CCSpriteFrameCache:: sharedSpriteFrameCache()-> spriteFrameByName("p1.png");
                    _tank->setDisplayFrame(newFrame);
                    _tank->_speed = 1;
                    _tank->_kind = kBorn;
                    //
                    //[_tank topButtle];
                }
            }
        }
    }
    
    return false;
}