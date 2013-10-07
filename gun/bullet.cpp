#include "bullet.h"

#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QPushButton>
#include <QtCore/QTimer>
#include <math.h>
#include <QtWidgets/QGraphicsEllipseItem>

#include "gun.h"

using namespace gun;

Bullet::Bullet(QObject *parent)
	: QObject(parent)
{
}

Bullet::Bullet(QGraphicsScene *scene
		, Gun *newGun
		, QPushButton *fireButton)
{
	this->mScene = scene;
	this->mTime = 0;
	this->mTimer = new QTimer();
	this->mGun = newGun;
	connect(fireButton
		, SIGNAL(clicked())
		, this
		, SLOT(start()));
	connect(this->mTimer
		, SIGNAL(timeout())
		, this
		, SLOT(fly()));
}

void Bullet::start()
{
	if (mGun->rotationAngle() == 90) {
		mStartXCoordinate = 10;
		mStartYCoordinate = -40;
	}

	if ((mGun->rotationAngle() != 0) && (mGun->rotationAngle() != 90)) {
		qreal tempAngle = 0.0175 * (mGun->rotationAngle());
		qreal temp = 1 / tan(tempAngle);
		mStartXCoordinate = ((20 * temp  + 10) / (sqrt(1 + temp * temp))) + 20 * cos(tempAngle);
		mStartYCoordinate = ((10 * temp - 20) / (sqrt(1 + temp * temp))) - 20 * sin(tempAngle);
	}

	if (mGun->rotationAngle() == 0) {
		mStartXCoordinate = 40;
		mStartYCoordinate = 10;
	}

	if (this->mTimer->isActive()) {
		return;
	}

	mTimer->start(10);
	if (this->mBody != NULL) {
		delete(this->mBody);
	}

	this->mBody = new QGraphicsEllipseItem(0, 0, 8, 8);
	this->mBody->setPos(mStartXCoordinate,
		mStartYCoordinate);
	this->mScene->addItem(this->mBody);
}

void Bullet::fly()
{
	this->mTime = mTime + 0.04;
	if (mGun->rotationAngle() != 90) {
		mXCoordinate = mStartXCoordinate + (10 * mGun->powerLevel()
				* cos(0.0175 * mGun->rotationAngle()) * mTime);
	}

	mYCoordinate = mStartYCoordinate - (10 * mGun->powerLevel()
			* sin(0.0175 * mGun->rotationAngle()) * mTime) + (5 * mTime * mTime);
	if (mYCoordinate >= 10) {
		this->mTimer->stop();
		mTime = 0;
		return;
	}

	if (mGun->rotationAngle() != 90) {
		this->mBody->setX(mXCoordinate);
		this->mBody->setY(mYCoordinate);
	}

}

Bullet::~Bullet()
{
	delete this->mBody;
	delete this->mGun;
	delete this->mScene;
	delete this->mTimer;
}

















