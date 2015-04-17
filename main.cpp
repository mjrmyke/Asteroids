/*
 * Group 2
 * Harpreet Dhunna (leader)
 * Jason Whitlow
 * Myke Walker
 * Bert Ouyang
 * Jheovanny Camacho
 * Israel Ruvalcaba
 * Julian Coleman
 * Tatiana Duarte
 */

#include "mainwindow.h"
#include <QApplication>

// ADD DESC
int main(int argc, char *argv[])
{
  // create main event loop handler and parse command line arguments
  QApplication app(argc, argv);

  // create application main window & enter main event loop
  MainWindow window;
  window.setFixedSize(960,745);
  window.show();
  return app.exec();
}
