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
    tank->_isCanFire = true;
    
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

bool TankSprite::checkPoint(CCPoint pon)
{
    
    CCPoint tnp = pon;
    unsigned int tid;
    
    tid = _mapLayer->tileIDFromPosition(tnp);
    CCLog("%d!!!", tid);
    if (tid != 0 && tid != 9 && tid != 10 && tid != 37 && tid != 38 ) return true;
    
    return false;
}

void TankSprite::onFire()
{
    if (_life == 0) {
        return;
    }
    //CCLog("%d!!", _isCanFire);
    if (_kind == kBorn||_kind == kPlusStarOne) {
        if (_isCanFire == false) {
            return;
        }
        // 子弹方向即坦克方向
        _buttleOrientaion = _kAction;
        
        CCSprite *buttle = CCSprite::createWithSpriteFrameName("bullet.png");
        _map->addChild(buttle, -1);
        //CCLog("Build a buttle!");
    
        // 隐藏
        buttle->setVisible(false);
        _isCanFire = false;
        
        this->fire(buttle, (TankAction)_buttleOrientaion);
    }
}

void TankSprite::fire(CCSprite *buttle, TankAction buttleOrientation)
{
    CCPoint ptn;
    switch (buttleOrientation) {
        case kUp:
            
            CCLOG("%f",this->getPosition().x);
            
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
    
    CCFiniteTimeAction *seq=CCSequence::create(ac1,ac2,CCCallFunc::create(this, callfunc_selector(TankSprite::makeCanFire)),NULL);
    
    buttle->runAction(seq);
}

void TankSprite::makeCanFire()
{
    CCLog("I can Fire!!!");
    _isCanFire = true;
}