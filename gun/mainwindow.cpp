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
    this->xCoordinate = 0;
    this->yCoordinate = 0;
    this->ellipse = new QGraphicsEllipseItem(xCoordinate,yCoordinate, 10, 10);
    this->timer = new QTimer();
    connect(this->timer, SIGNAL(timeout()), this, SLOT(Increase()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(Start()));
}

void MainWindow::Start()
{
    this->timer->start(10);
    if (xCoordinate != 0)
    {
        delete(ellipse);
        xCoordinate = 0;
        yCoordinate = 0;
        this->ellipse = new QGraphicsEllipseItem(xCoordinate,yCoordinate, 10, 10);
    }
    ellipse = PrintRow();
}

void MainWindow::Increase()
{
    ++xCoordinate;
    ellipse->setX(this->xCoordinate);
    yCoordinate = (0.01 * xCoordinate * xCoordinate) - (2 * xCoordinate);
    ellipse->setY(this->yCoordinate);
    if (yCoordinate > 30)
        this->timer->stop();
}

QGraphicsRectItem * MainWindow::PrintRect()
{
    QGraphicsRectItem *rect = scene.addRect(0, -18, 40, 20);
    QTransform transform;
    transform.rotate(127);
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
