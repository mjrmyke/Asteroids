#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>

class Scene;

class MainWindow : public QMainWindow
{
public:
    MainWindow();// constructor

private:
    Q_OBJECT
    QGraphicsView *view;
    Scene *game;// Game area
    Scene *intro;// empty area for intro

public slots:
   void StartButton_Clicked();

};

#endif  // MAINWINDOW_H
