#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QPushButton>
#include <QtCore/QTimer>

namespace gun {

class Gun;

/// Class which represents a flying bullet
class Bullet : public QObject
{
	Q_OBJECT

public slots:
	/// Method which represents start of the flight
	void start();

	/// Method which represents flying process
	void fly();

public:
	/// Destructor
	~Bullet();

	explicit Bullet(QObject *parent = 0);

	/// Creates a bullet
	Bullet(QGraphicsScene *scene
		, Gun *newGun
		, QPushButton *fireButton);

private:
	/// The bullet itself
	QGraphicsEllipseItem *mBody; // Takes ownership

	/// Scene where the bullet flies
	QGraphicsScene *mScene; // Takes ownership

	/// Gun from which shot is made
	Gun *mGun; // Takes ownership

	/// X coordinate of the bullet
	qreal mXCoordinate;

	/// Start X coordinate of the bullet
	qreal mStartXCoordinate;

	/// Start Y coordinate of the bullet
	qreal mStartYCoordinate;

	/// Y coordinate of the bullet
	qreal mYCoordinate;

	/// Time of the flight
	qreal mTime;

	/// Timer
	QTimer *mTimer; // Takes ownership
};

}
