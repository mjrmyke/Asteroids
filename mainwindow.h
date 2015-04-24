#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QTimerEvent>
#include <QBasicTimer>

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
    QBasicTimer guiUpdater;

public slots:
   void StartButton_Clicked();

protected:
   void timerEvent(QTimerEvent *event);

};

#endif  // MAINWINDOW_H
