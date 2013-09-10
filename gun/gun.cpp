#include "gun.h"

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QtWidgets/QSlider>
#include <QtWidgets/QLabel>

gun::gun(QObject *parent) :
    QObject(parent){
}

gun::gun(QGraphicsScene *scene,
         QSlider *powerSlider,
         QSlider *angleSlider,
         QLabel *pLabel,
         QLabel *aLabel){
    this->body = scene->addRect(0,0,40,20);
    this->rotateAngle = 0;
    this->powerLabel = pLabel;
    this->angleLabel = aLabel;
    connect(angleSlider,
            SIGNAL(sliderMoved(int)),
            this, SLOT(SetAngle(int)));
    connect(powerSlider,
            SIGNAL(sliderMoved(int)),
            this, SLOT(SetPower(int)));
}

void gun::SetAngle(int angle){
    QTransform transform;
    transform.rotate(360 - angle);
    this->body->setTransform(transform);
    this->rotateAngle = angle;
    this->angleLabel->setNum(rotateAngle);
}

void gun::SetPower(int value){
    this->power = value;
    this->powerLabel->setNum(power);
}
