//
//  TankSprite.cpp
//  TankWar
//
//  Created by user on 13-9-3.
//
//

#include "TankSprite.h"
#include "MapLayer.h"

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
    // 方向默认向上
    tank->_kAction = kUp;
    
    return tank;
}

void TankSprite::moveUp()
{
    
    // 设置旋转方向
    this->setRotation(0);
    // 设置tank的方向
    _kAction=kUp;
    
    // tank当前坐标
    CCPoint tp=this->getPosition();
    // tank移动后坐标
    CCPoint tnp = ccp(tp.x, tp.y+this->boundingBox().size.height/2+_speed);
    
    // 边界检测
    if ((tp.y + this->boundingBox().size.height/2 + _speed) > _mapSize.height ) return;
    if (this->checkPoint(tnp)) return;
    
    tnp = ccp(tp.x - this->boundingBox().size.width/2,tp.y + this->boundingBox().size.height / 2 + _speed);
    if (this->checkPoint(tnp)) return;
    
    tnp = ccp(tp.x - this->boundingBox().size.width/3,tp.y + this->boundingBox().size.height / 2 + _speed);
    if (this->checkPoint(tnp)) return;
    
    tnp = ccp(tp.x + this->boundingBox().size.width/2,tp.y + this->boundingBox().size.height / 2 + _speed);
    if (this->checkPoint(tnp)) return;
    
    tnp = ccp(tp.x + this->boundingBox().size.width/3,tp.y + this->boundingBox().size.height / 2 + _speed);
    if (this->checkPoint(tnp)) return;
    
    this->setPosition(ccp(this->getPosition().x, this->getPosition().y+_speed));
}

void TankSprite::moveDown()
{
    
    
    this->setRotation(180);
    
    _kAction=kDown;
    
    CCPoint tp=this->getPosition();
    
    CCPoint tnp = ccp(tp.x, tp.y-this->boundingBox().size.height/2-_speed);
    
    //
    if ((tp.y - this->boundingBox().size.height/2 - _speed) < 0 ) return;
    
    if (this->checkPoint(tnp)) return;
    
    tnp = ccp(tp.x-this->boundingBox().size.width/2,tp.y - this->boundingBox().size.height/2 - _speed);
    if (this->checkPoint(tnp)) return;
    
    tnp = ccp(tp.x - this->boundingBox().size.width/3,tp.y - this->boundingBox().size.height / 2 - _speed);
    if (this->checkPoint(tnp)) return;
    
    tnp = ccp(tp.x + this->boundingBox().size.width/2,tp.y - this->boundingBox().size.height / 2 - _speed);
    if (this->checkPoint(tnp)) return;
    
    tnp = ccp(tp.x + this->boundingBox().size.width/3,tp.y - this->boundingBox().size.height / 2 - _speed);
    if (this->checkPoint(tnp)) return;
    
    this->setPosition(ccp(this->getPosition().x, this->getPosition().y-_speed));
}


void TankSprite::moveLeft()
{
    
    this->setRotation(-90);
    
    _kAction=kLeft;
    
    CCPoint tp=this->getPosition();
    
    CCPoint tnp = ccp(tp.x-this->boundingBox().size.width/2-_speed, tp.y);
    
    //
    if (tp.x-this->boundingBox().size.width/2-_speed < 0 ) return;
    
    if (this->checkPoint(tnp)) return;
    
    tnp = ccp(tp.x - this->boundingBox().size.width/2 - _speed,tp.y + this->boundingBox().size.height/2 - 2);
    if (this->checkPoint(tnp)) return;
    
    tnp = ccp(tp.x - this->boundingBox().size.width/2 - _speed,tp.y + this->boundingBox().size.height/3);
    if (this->checkPoint(tnp)) return;
    
    tnp = ccp(tp.x - this->boundingBox().size.width/2 - _speed,tp.y - this->boundingBox().size.height/2 + 2);
    if (this->checkPoint(tnp)) return;
    
    tnp = ccp(tp.x - this->boundingBox().size.width/2 - _speed,tp.y - this->boundingBox().size.height/3);
    if (this->checkPoint(tnp)) return;
    
    this->setPosition(ccp(this->getPosition().x-_speed, this->getPosition().y));
}


void TankSprite::moveRight()
{
    
    this->setRotation(90);
    
    _kAction=kRight;
    
    CCPoint tp=this->getPosition();
    
    CCPoint tnp = ccp(tp.x+this->boundingBox().size.width/2+_speed, tp.y);
    
    //
    if (tp.x+this->boundingBox().size.width/2+_speed > _mapSize.width ) return;
    if (this->checkPoint(tnp)) return;
    
    tnp = ccp(tp.x - this->boundingBox().size.width/2 + _speed,tp.y + this->boundingBox().size.height/2 - 2);
    if (this->checkPoint(tnp)) return;
    
    tnp = ccp(tp.x - this->boundingBox().size.width/2 + _speed,tp.y + this->boundingBox().size.height/3);
    if (this->checkPoint(tnp)) return;
    
    tnp = ccp(tp.x - this->boundingBox().size.width/2 + _speed,tp.y - this->boundingBox().size.height/2 + 2);
    if (this->checkPoint(tnp)) return;
    
    tnp = ccp(tp.x - this->boundingBox().size.width/2 + _speed,tp.y - this->boundingBox().size.height/3);
    if (this->checkPoint(tnp)) return;
    
    this->setPosition(ccp(this->getPosition().x+_speed, this->getPosition().y));
}


//检测坐标点
bool TankSprite::checkPoint(CCPoint pon)
{
    
    CCPoint tnp = pon;
    unsigned int tid;
    
    tid = _mapLayer->tileIDFromPosition(tnp);
    
    if (tid != 0 && tid != 9 && tid != 10 && tid != 37 && tid != 38 ) return true;
    
    return false;
}