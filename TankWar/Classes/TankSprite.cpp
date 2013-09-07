//
//  TankSprite.cpp
//  TankWar
//
//  Created by user on 13-9-3.
//
//

#include "TankSprite.h"
#include "MapLayer.h"
#import "SimpleAudioEngine.h"
#define FRAME(image) CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(image)

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

    CCSpriteFrame* frameButtle = FRAME("bullet.png");
    if (_kind == kBorn) {
        if (_isCanFire == false) return;
        
        // 子弹方向即坦克方向
        _buttleOrientation = _kAction;
        
        CCSprite *buttle = CCSprite::createWithSpriteFrame(frameButtle);
        _map->addChild(buttle, -1);
    
        // 隐藏
        buttle->setVisible(false);
        _isCanFire = false;
        
        this->fire(buttle, (TankAction)_buttleOrientation);
    }
}

void TankSprite::fire(CCSprite *buttle, TankAction buttleOrientation)
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
    CCFiniteTimeAction *seq=CCSequence::create(ac1,ac2,CCCallFunc::create(this, callfunc_selector(TankSprite::makeCanFire)),NULL);
    buttle->runAction(seq);
    
    _buttle = buttle;
    this->schedule(schedule_selector(TankSprite::checkBang), 1/60);
}

void TankSprite::makeCanFire()
{
    //CCLog("I can Fire!!!");
    _isCanFire = true;
}

void TankSprite::checkBang(float dt)
{
    CCPoint btPoint = _buttle->getPosition();
    unsigned int gid = _mapLayer->tileIDFromPosition(btPoint);
    
    if(gid == -1
       || checkLayer2()
       || checkHome()
       || checkWall()
       || checkStrongWall()){
        // 停止tank的碰撞检测定时器
        this->unschedule(schedule_selector(TankSprite::checkBang));
        // 从移除地图层移出buttle
        _buttle->removeFromParentAndCleanup(true);
        _isCanFire = true;
        _buttle = NULL;
        return;
    }
}

bool TankSprite::checkLayer2()
{
    // 如果基地不被保护，则检测基地上的材质
    if(!_isHomeProtect) return false;
    // 如果基地被保护，则遇到保护层时直接移出buttle
    CCPoint btPoint = _buttle->getPosition();
    unsigned gid = _mapLayer->tileIDFromPosition(btPoint);
    CCLOG("Gid:%d", gid);
    if (0 != gid) {
        return true;
    }
    return false;
}

bool TankSprite::checkHome()
{
    CCRect rc = homeRect;
    if (rc.containsPoint(_buttle->getPosition())) {
        CCLOG("isHomeProtect:%d", _isHomeProtect);
        // 如果基地被保护的话，则直接移除buttle
        if (_isHomeProtect) return true;
        // 如果基地不被保护的话
        if (!_isHomeDone){
            _isHomeDone = true;
            this->gameOver();
        }
        return true;
    }
    return false;
}

bool TankSprite::checkWall()
{
    CCPoint btPoint = _buttle->getPosition();
    unsigned gid,gid1,gid2,gid3,gid4;
    gid = _mapLayer->tileIDFromPosition(btPoint);
    
    
    if ( (_buttleOrientation == kUp) || ( _buttleOrientation == kDown))
    {
        
        gid1 = _mapLayer->tileIDFromPosition(ccp(btPoint.x - 8, btPoint.y));
        gid2 = _mapLayer->tileIDFromPosition(ccp(btPoint.x + 8, btPoint.y));
        gid3 = _mapLayer->tileIDFromPosition(ccp(btPoint.x - 16, btPoint.y));
        gid4 = _mapLayer->tileIDFromPosition(ccp(btPoint.x + 16, btPoint.y));
        
        
        if (gid == 29 || gid == 30 || gid == 2 || gid == 1)
        {
            
            _mapLayer->destpryTile(btPoint);
            
            
            if ((gid1 == 29 || gid1 == 30 || gid1 == 2 || gid1 == 1) && (gid2 == 29 || gid2 == 30 || gid2== 2 || gid2 == 1))
            {
                
                
                if (gid4 == 29 || gid4 == 30 || gid4 == 2 || gid4 == 1 )
                {
                    _mapLayer->destpryTile(ccp(btPoint.x - 8, btPoint.y));
                    _mapLayer->destpryTile(ccp(btPoint.x + 8, btPoint.y));
                    _mapLayer->destpryTile(ccp(btPoint.x + 16, btPoint.y));
                    return true;
                }
                else
                {
                    if (gid3 == 0)
                    {
                        _mapLayer->destpryTile(ccp(btPoint.x - 8, btPoint.y));
                        _mapLayer->destpryTile(ccp(btPoint.x + 8, btPoint.y));
                        return true;
                    } else if (gid3 == 29 || gid3 == 30 || gid3 == 2 || gid3 == 1)
                    {
                        _mapLayer->destpryTile(ccp(btPoint.x - 8, btPoint.y));
                        _mapLayer->destpryTile(ccp(btPoint.x - 16, btPoint.y));
                        _mapLayer->destpryTile(ccp(btPoint.x + 8, btPoint.y));
                        return true;
                    }else
                    {
                        _mapLayer->destpryTile(ccp(btPoint.x - 8, btPoint.y));
                        _mapLayer->destpryTile(ccp(btPoint.x + 8, btPoint.y));
                        return true;
                    }
                }
                
            }
            
            
            if ((gid1 == 29 || gid1 == 30 || gid1 == 2 || gid1 == 1) && gid2 == 0)
            {
                _mapLayer->destpryTile(ccp(btPoint.x - 8, btPoint.y));
                return true;
            }
            
            
            if (gid1 == 0 && (gid2 == 29 || gid2 == 30 || gid2== 2 || gid2 == 1))
            {
                _mapLayer->destpryTile(ccp(btPoint.x + 8, btPoint.y));
                return true;
            }
            
            
            if ((gid1 != 1 && gid1 != 2 && gid1 != 29 && gid1 != 30 && gid1 != 0) && (gid2 == 29 || gid2 == 30 || gid2== 2 || gid2 == 1))
            {
                _mapLayer->destpryTile(ccp(btPoint.x + 8, btPoint.y));
                return true;
            }
            
            
            if ((gid1 != 1 && gid1 != 2 && gid1 != 29 && gid1 != 30 && gid1 != 0) && gid2 == 0)
            {
                return true;
            }
            
            
            if ((gid2 != 1 && gid2 != 2 && gid2 != 29 && gid2 != 30 && gid2 != 0) && (gid1 == 29 || gid1 == 30 || gid1 == 2 || gid1 == 1))
            {
                _mapLayer->destpryTile(ccp(btPoint.x - 8, btPoint.y));
                return true;
            }
            
            
            if ((gid2 != 1 && gid2 != 2 && gid2 != 29 && gid2 != 30 && gid2 != 0) && gid1 == 0)
            {
                return true;
            }
            
            
            if (gid1 == 0 && gid2 == 0) {
                return true;
            }
        }
    }
    
    if (_buttleOrientation == kLeft || _buttleOrientation == kRight)
    {
        
        gid1 = _mapLayer->tileIDFromPosition(ccp(btPoint.x, btPoint.y - 8));
        gid2 = _mapLayer->tileIDFromPosition(ccp(btPoint.x, btPoint.y + 8));
        gid3 = _mapLayer->tileIDFromPosition(ccp(btPoint.x, btPoint.y - 16));
        gid4 = _mapLayer->tileIDFromPosition(ccp(btPoint.x, btPoint.y + 16));
        
        
        if (gid == 29 || gid == 30 || gid == 2 || gid == 1)
        {
            
            _mapLayer->destpryTile(btPoint);
            
            
            if ((gid1 == 29 || gid1 == 30 || gid1 == 2 || gid1 == 1) && (gid2 == 29 || gid2 == 30 || gid2== 2 || gid2 == 1))
            {
                
                
                if (gid4 == 29 || gid4 == 30 || gid4 == 2 || gid4 == 1 )
                {
                    _mapLayer->destpryTile(ccp(btPoint.x, btPoint.y - 8));
                    _mapLayer->destpryTile(ccp(btPoint.x, btPoint.y + 8));
                    _mapLayer->destpryTile(ccp(btPoint.x, btPoint.y + 16));
                    return true;
                }
                else
                {
                    if (gid3 == 0)
                    {
                        _mapLayer->destpryTile(ccp(btPoint.x, btPoint.y - 8));
                        _mapLayer->destpryTile(ccp(btPoint.x, btPoint.y + 8));
                        return true;
                    } else if (gid3 == 29 || gid3 == 30 || gid3 == 2 || gid3 == 1)
                    {
                        _mapLayer->destpryTile(ccp(btPoint.x, btPoint.y - 8));
                        _mapLayer->destpryTile(ccp(btPoint.x, btPoint.y - 16));
                        _mapLayer->destpryTile(ccp(btPoint.x, btPoint.y + 8));
                        return true;
                    }else
                    {
                        _mapLayer->destpryTile(ccp(btPoint.x, btPoint.y - 8));
                        _mapLayer->destpryTile(ccp(btPoint.x, btPoint.y + 8));
                        return true;
                    }
                }
                
            }
            
            
            if ((gid1 == 29 || gid1 == 30 || gid1 == 2 || gid1 == 1) && gid2 == 0)
            {
                _mapLayer->destpryTile(ccp(btPoint.x, btPoint.y - 8));
                return true;
            }
            
            
            if (gid1 == 0 && (gid2 == 29 || gid2 == 30 || gid2== 2 || gid2 == 1))
            {
                _mapLayer->destpryTile(ccp(btPoint.x, btPoint.y + 8));
                return true;
            }
            
            
            if ((gid1 != 1 && gid1 != 2 && gid1 != 29 && gid1 != 30 && gid1 != 0) && (gid2 == 29 || gid2 == 30 || gid2== 2 || gid2 == 1))
            {
                _mapLayer->destpryTile(ccp(btPoint.x, btPoint.y + 8));
                return true;
            }
            
            
            if ((gid1 != 1 && gid1 != 2 && gid1 != 29 && gid1 != 30 && gid1 != 0) && gid2 == 0)
            {
                return true;
            }
            
            
            if ((gid2 != 1 && gid2 != 2 && gid2 != 29 && gid2 != 30 && gid2 != 0) && (gid1 == 29 || gid1 == 30 || gid1 == 2 || gid1 == 1))
            {
                _mapLayer->destpryTile(ccp(btPoint.x, btPoint.y - 8));
                return true;
            }
            
            
            if ((gid2 != 1 && gid2 != 2 && gid2 != 29 && gid2 != 30 && gid2 != 0) && gid1 == 0)
            {
                return true;
            }
            
            
            if (gid1 == 0 && gid2 == 0) {
                return true;
            }
            
        }
        
    }

    return false;
}

bool TankSprite::checkStrongWall()
{
    
    CCPoint btPoint = _buttle->getPosition();
    unsigned gid = _mapLayer->tileIDFromPosition(btPoint);
    
    
    if (gid == 5 || gid ==6 ||gid ==33 ||gid == 34 ) {
        
        if (_kind == kPlusStarThree) {
            
            _mapLayer->destpryTile(ccp(btPoint.x,btPoint.y));
            
            _isCanFire = true;
            if ( _buttleOrientation == kUp){
                if (gid == 33) {
                    
                    _mapLayer->destpryTile(ccp(btPoint.x,btPoint.y + 8));
                    _mapLayer->destpryTile(ccp(btPoint.x + 8,btPoint.y));
                    _mapLayer->destpryTile(ccp(btPoint.x+8,btPoint.y+8));
                }else if (gid == 34){
                    
                    _mapLayer->destpryTile(ccp(btPoint.x,btPoint.y+8));
                    _mapLayer->destpryTile(ccp(btPoint.x - 8,btPoint.y));
                    _mapLayer->destpryTile(ccp(btPoint.x-8,btPoint.y+8));
                }
                return true;
                
            }else if (_buttleOrientation == kDown){
                if (gid == 5) {
                    
                    _mapLayer->destpryTile(ccp(btPoint.x,btPoint.y - 8));
                    _mapLayer->destpryTile(ccp(btPoint.x + 8,btPoint.y));
                    _mapLayer->destpryTile(ccp(btPoint.x + 8,btPoint.y-8));
                }else if (gid == 6){
                    
                    _mapLayer->destpryTile(ccp(btPoint.x,btPoint.y-8));
                    _mapLayer->destpryTile(ccp(btPoint.x - 8,btPoint.y));
                    _mapLayer->destpryTile(ccp(btPoint.x-8,btPoint.y-8));
                }
                return true;
                
            }else if (_buttleOrientation == kLeft){
                if (gid == 34){
                    
                    _mapLayer->destpryTile(ccp(btPoint.x - 8,btPoint.y));
                    _mapLayer->destpryTile(ccp(btPoint.x,btPoint.y +8));
                    _mapLayer->destpryTile(ccp(btPoint.x-8,btPoint.y+8));
                }else if(gid == 6){
                    
                    _mapLayer->destpryTile(ccp(btPoint.x- 8,btPoint.y));
                    _mapLayer->destpryTile(ccp(btPoint.x,btPoint.y - 8));
                    _mapLayer->destpryTile(ccp(btPoint.x - 8,btPoint.y -8));
                }
                return true;
            }else if (_buttleOrientation == kRight){
                
                if (gid == 5){
                    
                    _mapLayer->destpryTile(ccp(btPoint.x + 8,btPoint.y));
                    _mapLayer->destpryTile(ccp(btPoint.x,btPoint.y -8));
                    _mapLayer->destpryTile(ccp(btPoint.x+8,btPoint.y-8));
                }else if(gid == 33){
                    
                    _mapLayer->destpryTile(ccp(btPoint.x,btPoint.y + 8));
                    _mapLayer->destpryTile(ccp(btPoint.x +8,btPoint.y));
                    _mapLayer->destpryTile(ccp(btPoint.x +8,btPoint.y +8));
                }
                return true;
            }
            
        }else {
            return true;
        }
        
    }
    return false;
    
}

void TankSprite::gameOver()
{
    _mapLayer->gameOver();
}