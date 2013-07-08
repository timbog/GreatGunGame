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
    QTimer *timer;
    QGraphicsRectItem *gun;
    QGraphicsEllipseItem *bullet;
    qreal rotateAngle;

public slots:
    QGraphicsRectItem *PrintRect();
    QGraphicsEllipseItem *PrintRow();
    void Start();
    void Increase();
    void RotateGun(int angle);
    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
