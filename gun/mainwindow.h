#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include "gun.h"
#include "bullet.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    // Scene
    QGraphicsScene *scene;

    // Gun which shoots
    Gun *newGun;

    // Bullet which flies
    Bullet *newBullet;
private:
    Ui::MainWindow *ui;
};
