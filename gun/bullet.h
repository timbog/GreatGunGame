#pragma once
#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsScene>
#include "gun.h"
#include <QtWidgets/QPushButton>
#include <QTimer>

// Class which represents a flying bullet
class bullet : public QObject{
    Q_OBJECT
public:
    explicit bullet(QObject *parent = 0);

    bullet(QGraphicsScene *scene,
           gun *newGun,
           QPushButton *fireButton);

    // The bullet itself
    QGraphicsEllipseItem *body;

    // Scene where the bullet flies
    QGraphicsScene *scene;

    // Gun from which shot is made
    gun *powerGun;

    // X coordinate of the bullet
    qreal xCoordinate;

    // Start X coordinate of the bullet
    qreal startXCoordinate;

    // Start Y coordinate of the bullet
    qreal startYCoordinate;

    // Y coordinate of the bullet
    qreal yCoordinate;

    // Time of the flight
    qreal time;

    // Timer
    QTimer *timer;

    
signals:
    
public slots:
    // Method which represents start of the flight
    void Start();

    //Method which represents flying process
    void Fly();    
};

#endif // BULLET_H
