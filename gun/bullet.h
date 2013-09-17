#pragma once

#include <QObject>
#include <QGraphicsScene>
#include <QtWidgets/QPushButton>
#include <QTimer>

class Gun;

// Class which represents a flying bullet
class Bullet : public QObject {
    Q_OBJECT
public:
    explicit Bullet(QObject *parent = 0);

    //Creates a bullet
    Bullet(QGraphicsScene *scene
        , Gun *newGun
        , QPushButton *fireButton);
public slots:
    // Method which represents start of the flight
    void start();

    //Method which represents flying process
    void fly();
private:
    // The bullet itself
    QGraphicsEllipseItem *mBody;

    // Scene where the bullet flies
    QGraphicsScene *mScene;

    // Gun from which shot is made
    Gun *mGun;

    // X coordinate of the bullet
    qreal mXCoordinate;

    // Start X coordinate of the bullet
    qreal mStartXCoordinate;

    // Start Y coordinate of the bullet
    qreal mStartYCoordinate;

    // Y coordinate of the bullet
    qreal mYCoordinate;

    // Time of the flight
    qreal mTime;

    // Timer
    QTimer *mTimer;
};
