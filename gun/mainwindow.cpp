#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <math.h>
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
    xCoordinate = 40;
    yCoordinate = 10;
    this->timer = new QTimer();
    connect(this->timer, SIGNAL(timeout()), this, SLOT(Increase()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(Start()));
    connect(ui->verticalSlider, SIGNAL(sliderMoved(int)), this, SLOT(RotateGun(int)));
    connect(ui->horizontalSlider, SIGNAL(sliderMoved(int)), this, SLOT (SetSpeed(int)));
}

void MainWindow::SetSpeed(int value)
{
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
        xCoordinate = 10;
        yCoordinate = -40;
    }
    else if (rotateAngle != 0)
    {
        qreal tempAngle = 0.0175 * (rotateAngle);
        qreal temp = 1 / tan(tempAngle);
        xCoordinate = ((20 * temp  + 10)/(sqrt(1 + temp * temp))) + 20 * cos(tempAngle);
        yCoordinate = ((10 * temp - 20)/(sqrt(1 + temp * temp))) - 20 * sin(tempAngle);
    }
    else
    {
        xCoordinate = 40;
        yCoordinate = 10;
    }
    bullet = new QGraphicsEllipseItem;
    bullet = PrintRow();
    ui->label_3->setNum(yCoordinate);
    this->timer->start(40);
}

void MainWindow::RotateGun(int angle)
{
    if (timer->isActive())
        return;
    if (angle <= 90)
    {
        QTransform transform;
        transform.rotate(angle - 90);
        gun->setTransform(transform);
        this->rotateAngle = 90 - angle;
        ui->label->setNum(rotateAngle);
    }
}

void MainWindow::Increase()
{
    this->time = time + 0.04;
    if (rotateAngle != 90)
        xCoordinate = xCoordinate + (speed * cos(0.0175 * rotateAngle) * time);
    yCoordinate = yCoordinate - (speed * sin(0.0175 * rotateAngle) * time) + (5 * time * time);
    if (yCoordinate > 5)
    {
        this->timer->stop();
        time = 0;
        return;
    }
    if (rotateAngle != 90)
        bullet->setX(xCoordinate);
    bullet->setY(yCoordinate);
    //ui->label_3->setNum(bullet->x());
}

QGraphicsRectItem * MainWindow::PrintRect()
{
    QGraphicsRectItem *rect = scene.addRect(0, 0, 40, 20);
    return rect;
}

QGraphicsEllipseItem * MainWindow::PrintRow()
{
    QGraphicsEllipseItem *row = scene.addEllipse(this->xCoordinate, this->yCoordinate, 8, 8);
    return row;
}


MainWindow::~MainWindow()
{
    delete ui;
}
