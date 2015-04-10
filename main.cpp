/* Group 2
 * Harpreet Dhunna (leader)
 * Jason Whitlow
 * Myke Walker
 * Bert Ouyang
 * Giovanni Camacho
 * Israel Ruvalcaba
 */

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{

  // create main event loop handler and parse command line arguments
  QApplication app(argc, argv);
  //QApplication::exec();
  //QCoreApplication::exec();

  // create application main window & enter main event loop
  MainWindow window;
  window.setFixedSize(800,600);
  window.show();
  return app.exec();
}
