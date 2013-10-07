#include "gun.h"

#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsRectItem>
#include <QtWidgets/QSlider>
#include <QtWidgets/QLabel>

using namespace gun;

Gun::Gun(QObject *parent)
	: QObject(parent)
{
}

Gun::Gun(QGraphicsScene *scene
		, QSlider *powerSlider
		, QSlider *angleSlider
		, QLabel *pLabel
		, QLabel *aLabel)
{
	this->mBody = scene->addRect(0, 0, 40, 20);
	this->mRotateAngle = 0;
	this->mPowerLabel = pLabel;
	this->mAngleLabel = aLabel;
	connect(angleSlider
		, SIGNAL(sliderMoved(int))
		, this
		, SLOT(setAngle(int)));
	connect(powerSlider
		, SIGNAL(sliderMoved(int))
		, this
		, SLOT(setPower(int)));
}

void Gun::setAngle(int angle)
{
	QTransform transform;
	transform.rotate(360 - angle);
	this->mBody->setTransform(transform);
	this->mRotateAngle = angle;
	this->mAngleLabel->setNum(mRotateAngle);
}

void Gun::setPower(int value)
{
	this->mPower = value;
	this->mPowerLabel->setNum(mPower);
}

int Gun::rotationAngle()
{
	return this->mRotateAngle;
}

int Gun::powerLevel()
{
	return this->mPower;
}

Gun::~Gun()
{
	delete this->mAngleLabel;
	delete this->mPowerLabel;
	delete this->mBody;
}



