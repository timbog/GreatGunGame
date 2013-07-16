#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <math.h>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);
    ui->graphicsView->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
    gun = PrintRect();
    rotateAngle = 0;
    this->time = 0;
    startXCoordinate = 40;
    startYCoordinate = 10;
    bullet = new QGraphicsEllipseItem(startXCoordinate, startYCoordinate, 10, 10);
    this->timer = new QTimer();
    connect(this->timer, SIGNAL(timeout()), this, SLOT(Increase()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(Start()));
    connect(ui->verticalSlider, SIGNAL(sliderMoved(int)), this, SLOT(RotateGun(int)));
    connect(ui->horizontalSlider, SIGNAL(sliderMoved(int)), this, SLOT (SetSpeed(int)));
}

void MainWindow::SetSpeed(int value)
{
    if (timer->isActive())
        return;
    this->speed = value;
    ui->label_2->setNum(speed);
}

void MainWindow::Start()
{
    if (timer->isActive())
        return;
    delete(bullet);
    if (rotateAngle == 90)
    {
        startXCoordinate = 10;
        startYCoordinate = -40;
    }
    else if (rotateAngle != 0)
    {
        qreal tempAngle = 0.0175 * (rotateAngle);
        qreal temp = 1 / tan(tempAngle);
        startXCoordinate = ((20 * temp  + 10)/(sqrt(1 + temp * temp))) + 20 * cos(tempAngle);
        startYCoordinate = ((10 * temp - 20)/(sqrt(1 + temp * temp))) - 20 * sin(tempAngle);
    }
    else
    {
        startXCoordinate = 40;
        startYCoordinate = 10;
    }
    bullet = new QGraphicsEllipseItem(0,0, 8, 8);
    bullet->setPos(startXCoordinate, startYCoordinate);
    scene.addItem(bullet);
    this->timer->start(10);
}

void MainWindow::RotateGun(int angle)
{
    if (timer->isActive())
        return;
    if (angle <= 90)
    {
        QTransform transform;
        transform.rotate(360 - angle);
        gun->setTransform(transform);
        this->rotateAngle = angle;
        ui->label->setNum(rotateAngle);
    }
}

void MainWindow::Increase()
{

    this->time = time + 0.04;
    if (rotateAngle != 90)
        xCoordinate = startXCoordinate + (10 * speed * cos(0.0175 * rotateAngle) * time);
    yCoordinate = startYCoordinate - (10 * speed * sin(0.0175 * rotateAngle) * time) + (5 * time * time);
    if (yCoordinate >= 10)
    {
        this->timer->stop();
        time = 0;
        return;
    }

    if (rotateAngle != 90)
        bullet->setX(xCoordinate);
    bullet->setY(yCoordinate);
}

QGraphicsRectItem * MainWindow::PrintRect()
{
    QGraphicsRectItem *rect = scene.addRect(0, 0, 40, 20);
    return rect;
}

QGraphicsEllipseItem * MainWindow::PrintRow()
{
    QGraphicsEllipseItem *row = scene.addEllipse(this->startXCoordinate, this->startYCoordinate, 8, 8);
    return row;
}


MainWindow::~MainWindow()
{
    delete ui;
}
