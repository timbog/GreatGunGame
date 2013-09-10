#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "gun.h"
#include "bullet.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    // Scene
    QGraphicsScene *scene;

    // Gun which shoots
    gun *newGun;

    // Bullet which flies
    bullet *newBullet;
public slots:

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
