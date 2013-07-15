#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    QGraphicsScene scene;
    qreal xCoordinate;
    qreal yCoordinate;
    qreal startXCoordinate;
    qreal startYCoordinate;
    QTimer *timer;
    QGraphicsRectItem *gun;
    QGraphicsEllipseItem *bullet;
    qreal rotateAngle;
    qreal time;
    qreal speed;

public slots:
    QGraphicsRectItem *PrintRect();
    QGraphicsEllipseItem *PrintRow();
    void Start();
    void Increase();
    void RotateGun(int angle);
    void SetSpeed(int value);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
