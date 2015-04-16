#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QMediaPlayer>

class Scene;

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

public slots:
   void StartButton_Clicked();

};

#endif  // MAINWINDOW_H
