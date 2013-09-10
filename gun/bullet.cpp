#include "bullet.h"

#include <QGraphicsScene>
#include <QtWidgets/QPushButton>
#include <QTimer>
#include <math.h>
#include <QGraphicsEllipseItem>

#include "gun.h"

bullet::bullet(QObject *parent) :
    QObject(parent){
}

bullet::bullet(QGraphicsScene *scene,
               gun *newGun,
               QPushButton *fireButton)
{
    this->time = 0;
    this->scene = scene;
    this->timer = new QTimer();
    this->powerGun = newGun;
    connect(fireButton,
            SIGNAL(clicked()),
            this, SLOT(Start()));
    connect(this->timer,
            SIGNAL(timeout()),
            this, SLOT(Fly()));
}

void bullet::Start(){
    if (powerGun->rotateAngle == 90){
        startXCoordinate = 10;
        startYCoordinate = -40;
    }
    if ((powerGun->rotateAngle != 0) && (powerGun->rotateAngle != 90)){
        qreal tempAngle = 0.0175 * (powerGun->rotateAngle);
        qreal temp = 1 / tan(tempAngle);
        startXCoordinate = ((20 * temp  + 10)/(sqrt(1 + temp * temp))) + 20 * cos(tempAngle);
        startYCoordinate = ((10 * temp - 20)/(sqrt(1 + temp * temp))) - 20 * sin(tempAngle);
    }
    if (powerGun->rotateAngle == 0){
        startXCoordinate = 40;
        startYCoordinate = 10;
    }
    if (this->timer->isActive())
        return;
    timer->start(10);
    delete(this->body);
    this->body = new QGraphicsEllipseItem(0, 0, 8, 8);
    this->body->setPos(startXCoordinate,
                       startYCoordinate);
    this->scene->addItem(this->body);
}

void bullet::Fly(){
    this->time = time + 0.04;
    if (powerGun->rotateAngle != 90)
            xCoordinate = startXCoordinate + (10 * powerGun->power * cos(0.0175 * powerGun->rotateAngle) * time);
    yCoordinate = startYCoordinate - (10 * powerGun->power * sin(0.0175 * powerGun->rotateAngle) * time) + (5 * time * time);
    if (yCoordinate >= 10){
        this->timer->stop();
        time = 0;
        return;
    }
    if (powerGun->rotateAngle != 90)
        this->body->setX(xCoordinate);
    this->body->setY(yCoordinate);
}















