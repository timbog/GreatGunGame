#pragma once
#ifndef GUN_H
#define GUN_H

#include <QObject>
#include <QGraphicsScene>
#include <QtWidgets/QSlider>
#include <QtWidgets/QLabel>

// Class which represents a gun
class gun : public QObject{
    Q_OBJECT
public:
    explicit gun(QObject *parent = 0);
    
    gun(QGraphicsScene *scene,
        QSlider *powerSlider,
        QSlider *angleSlider,
        QLabel *pLabel,
        QLabel *aLabel);

    // The gun itself
    QGraphicsRectItem *body;

    //Label which shows power of the shot
    QLabel *powerLabel;

    // Label which shows angle of the shot
    QLabel *angleLabel;

    // Rotation angle
    qreal rotateAngle;

    // Power of the shot
    qreal power;

signals:
    
public slots:
    // Method which is needed to set a rotation angle
    void SetAngle(int angle);

    // Method which is needed to set a power of the shot
    void SetPower(int value);   
};

#endif // GUN_H
