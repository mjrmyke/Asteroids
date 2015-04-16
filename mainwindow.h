#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>

class Scene;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();// constructor

private:
    QGraphicsView *view;
    Scene *game;// Game area
    Scene *intro;// empty area for intro

public slots:
   void StartButton_Clicked();

};

#endif  // MAINWINDOW_H
