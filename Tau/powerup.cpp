#include "powerup.h"
#include <constants.h>
#include <helper.h>
#include <QPainter>
#include <ggamescene.h>
#include <QDebug>
#include <QtConcurrent>

powerup::powerup(int id, GGameScene *parent)
{
    this->parent = parent;
    this->id = id;
    t = static_cast<powerUpType>(qrand() % (int)powerUpType::NUM_POWERUPTYPES);
    position = new QPointF(randomInBound(windowWidth/2-arenaRadius/2,windowWidth/2+arenaRadius/2),
                      randomInBound(windowHeight/2-arenaRadius/2,windowHeight/2+arenaRadius/2));
    radius = powerUpRadius;
    rekt = new QRectF(position->x()-radius,position->y()-radius,radius*2,radius*2);
    enabled = false;
    QtConcurrent::run(this,&powerup::fadeIn);
    QTimer* rotator = new QTimer();
    QObject::connect(rotator,SIGNAL(timeout()),this,SLOT(rotate()));
    rotator->start(refreshInterval);
}

void powerup::enable()
{
    if(enabled){
        return;
    }
    if(t==powerUpType::random){
        while(t==powerUpType::random || t==powerUpType::arrow){
            t = static_cast<powerUpType>(qrand() % (int)powerUpType::NUM_POWERUPTYPES);
        }
    }
    affectedPlayer = parent->p[parent->mostRecent];
    switch(this->puptype()){
    case powerUpType::ballSizeUp: QtConcurrent::run((parent->b),&Ball::sizeUp); parent->sizeUp->play(); break;
    case powerUpType::paddleSizeUp: QtConcurrent::run(affectedPlayer,&Player::sizeUp); parent->sizeUp->play(); break;
    case powerUpType::paddleSizeDown: QtConcurrent::run(affectedPlayer,&Player::sizeDown); parent->sizeDown->play(); break;
    case powerUpType::arrow: parent->b->setAngle((int)(this->angle*16)); break;
    case powerUpType::warp: parent->b->warper->start(500); break;
    case powerUpType::lightning: parent->b->setSpeed(parent->b->getSpeed()+3); break;
    case powerUpType::wobble: parent->b->wobbler->start(100); break;
    case powerUpType::ghost: parent->b->startGhost(); break;
    case powerUpType::snail:parent->b->setSpeed(parent->b->getSpeed()-3); break;
    default: break;
    }
    enabled = true;
    QTimer::singleShot(powerUpEnabledTime,Qt::PreciseTimer,this,SLOT(disable()));
}

void powerup::disable()
{
    if(disabled){
        return;
    }
    if(!enabled){
        return;
    }
    switch(this->puptype()){
    case powerUpType::ballSizeUp: QtConcurrent::run(parent->b,&Ball::sizeDown); parent->sizeDown->play(); break;
    case powerUpType::paddleSizeUp: QtConcurrent::run(affectedPlayer,&Player::sizeDown); parent->sizeDown->play(); break;
    case powerUpType::paddleSizeDown: QtConcurrent::run(affectedPlayer,&Player::sizeUp); parent->sizeUp->play(); break;
    case powerUpType::arrow: /*do nothing*/ break;
    case powerUpType::warp: parent->b->warper->stop(); break;
    case powerUpType::lightning: parent->b->setSpeed(parent->b->getSpeed()-3); break;
    case powerUpType::wobble: parent->b->wobbler->stop(); break;
    case powerUpType::ghost: parent->b->stopGhost(); break;
    case powerUpType::snail: parent->b->setSpeed(parent->b->getSpeed()+3); break;
    default: break;
    }
    disabled = true;
}

void powerup::setPen(QPen pen)
{
    this->pen = pen;
}

void powerup::setBrush(QBrush brush)
{
    this->brush = brush;
}

QPointF* powerup::pos()
{
    return position;
}

powerUpType powerup::puptype()
{
    return t;
}

int powerup::rad()
{
    return radius;
}

void powerup::paint(QPainter *painter, const QStyleOptionGraphicsItem * /*unused*/, QWidget * /*unused*/)
{
    if(!enabled){
        painter->setPen(this->pen);
        painter->setBrush(this->brush);
        painter->setOpacity(opacity);
        painter->translate(position->x(),position->y());
        painter->rotate(angle);
        painter->drawImage(QRectF(-radius,-radius,radius*2,radius*2), QImage(icos[(int)t]));
    }
}

QRectF powerup::rect()
{
    return *rekt;
}

QRectF powerup::boundingRect() const
{
    return *rekt;
}

void powerup::rotate()
{
    angle+=3;
}

void powerup::fadeIn()
{
    while(opacity < 1){
        opacity+=0.1;
        QThread::msleep(refreshInterval);
    }
}
