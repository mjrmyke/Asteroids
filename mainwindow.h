#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Scene;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();// constructor

private:
    Scene *scene;// the uh... scene

public slots:
   void StartButton_Clicked();

};

#endif  // MAINWINDOW_H
