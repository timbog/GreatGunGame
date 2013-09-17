#include "mainwindow.h"

#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>

#include "gun.h"
#include "bullet.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
    newGun = new Gun(scene
        , ui->powerSlider
        , ui->angleSlider
        , ui->powerLabel
        , ui->angleLabel);
    newBullet = new Bullet(scene
        ,newGun
        ,ui->fireButton);
}

MainWindow::~MainWindow() {
    delete ui;
}
