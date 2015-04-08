#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Scene;

class MainWindow : public QMainWindow
{
public:
    MainWindow();// constructor

private:
    Scene *scene;// the uh... scene

public slots:
   void newGame(Scene *scene);

};

#endif  // MAINWINDOW_H
