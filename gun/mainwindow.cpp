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
    rotateAngle = 53;
    this->xCoordinate = 0;
    this->yCoordinate = -10;
    this->bullet = new QGraphicsEllipseItem(xCoordinate,yCoordinate, 10, 10);
    this->timer = new QTimer();
    connect(this->timer, SIGNAL(timeout()), this, SLOT(Increase()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(Start()));
    connect(ui->verticalSlider, SIGNAL(sliderMoved(int)), this, SLOT(RotateGun(int)));
}

void MainWindow::Start()
{
    if ((xCoordinate != 0) && (!timer->isActive()))
    {
        delete(bullet);
        xCoordinate = 0;
        yCoordinate = -10;
        this->bullet = new QGraphicsEllipseItem(xCoordinate,yCoordinate, 10, 10);
    }
    else if (timer->isActive())
        return;
    this->timer->start(10);
    bullet = PrintRow();
}

void MainWindow::RotateGun(int angle)
{
    if (timer->isActive())
        return;
    if (angle <= 91)
    {
        QTransform transform;
        transform.rotate(angle - 90);
        gun->setTransform(transform);
        this->rotateAngle = angle;
        ui->label->setNum(90 - angle);
    }
}

void MainWindow::Increase()
{
    ++xCoordinate;
    if (rotateAngle != 0)
        bullet->setX(this->xCoordinate);
    yCoordinate = ((-2) * cos(0.0175 * rotateAngle) * xCoordinate) + (0.01 * xCoordinate * xCoordinate);
    bullet->setY(this->yCoordinate);
    if (yCoordinate > 10)
        this->timer->stop();
}

QGraphicsRectItem * MainWindow::PrintRect()
{
    QGraphicsRectItem *rect = scene.addRect(0, -10, 40, 20);
    return rect;
}

QGraphicsEllipseItem * MainWindow::PrintRow()
{
    QGraphicsEllipseItem *row = scene.addEllipse(this->xCoordinate, this->yCoordinate, 10, 10);
    return row;
}


MainWindow::~MainWindow()
{
    delete ui;
}
