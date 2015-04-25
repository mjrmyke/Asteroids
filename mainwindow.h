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

    QGraphicsRectItem *shipShields;
    mainship *ship;

public slots:
   void StartButton_Clicked();
   void shipShieldHUDUpdate(int shields);

};

#endif  // MAINWINDOW_H
