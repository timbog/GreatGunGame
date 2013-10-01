#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include "gun.h"
#include "bullet.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	/// Destructor
	~MainWindow();

	explicit MainWindow(QWidget *parent = 0);

private:
	/// Scene
	QGraphicsScene *mScene; // Takes ownership

	/// Gun which shoots
	Gun *mGun; // Takes ownership

	/// Bullet which flies
	Bullet *mBullet; // Takes ownership

	Ui::MainWindow *mUi; // Takes ownership
};
