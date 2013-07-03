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

public:
    int xCoordinate;

public:
    int yCoordinate;

public:
    QTimer *timer;

public:
    QGraphicsRectItem *rectan;

public:
    QGraphicsEllipseItem *ellipse;

public slots:
    QGraphicsRectItem *PrintRect();

public slots:
    QGraphicsEllipseItem *PrintRow();

public slots:
    void Start();

public slots:
    void Increase();
    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
