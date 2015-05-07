#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QTimerEvent>
#include <QBasicTimer>
#include "scene.h"
#include "mainship.h"
#include "bullet.h"
#include "asteroid.h"
#include <QMenuBar>
#include <QBrush>
#include <stdlib.h>
#include <time.h>

//class Scene;

class MainWindow : public QMainWindow
{
public:
    MainWindow();// constructor

private:
    Q_OBJECT
    QMediaPlayer * music;
    QGraphicsView *view;
    Scene *game;// Game area
    Scene *intro;// empty area for intro
    QGraphicsTextItem* deadtext;

    QGraphicsRectItem *shipShields;
    mainship *ship;

    QBasicTimer asteroidSpawner;
    void spawnAsteroids();

protected:
    // Fires whenever the timer fires.
    void timerEvent(QTimerEvent *event);

public slots:
   void StartButton_Clicked();
   void shipShieldHUDUpdate(int shields);

};

#endif  // MAINWINDOW_H
