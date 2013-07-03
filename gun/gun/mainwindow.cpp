#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);
    ui->graphicsView->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
    rectan = PrintRect();
    scene.addEllipse(0,10, 10, 10);
    this->xCoordinate = -5;
    this->yCoordinate = -20;
    this->ellipse = new QGraphicsEllipseItem(xCoordinate,yCoordinate, 10, 10);
    this->timer = new QTimer();
    connect(this->timer, SIGNAL(timeout()), this, SLOT(Increase()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(Start()));
}

void MainWindow::Start()
{
    this->timer->start(10);
    ellipse = PrintRow();
}

void MainWindow::Increase()
{
    ++xCoordinate;
    ellipse->setX(this->xCoordinate);
     --yCoordinate;
    ellipse->setY(this->yCoordinate);
}

QGraphicsRectItem * MainWindow::PrintRect()
{
    QGraphicsRectItem *rect = scene.addRect(0, 0, 40, 20);
    QTransform transform;
    transform.rotate(135);
    rect->setTransform(transform);
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
