#include "mainwindow.h"
#include "scene.h"
#include "mainship.h"
#include "bullet.h"

#include <QMenuBar>
#include <QGraphicsView>
//#include <QStatusBar>



MainWindow::MainWindow():QMainWindow()
{
    // add drop down menus
    QMenu* StartMenu = menuBar()->addMenu("&Start");
    QMenu* CloseMenu =  menuBar()->addMenu("&Close");

    QAction* CloseAction = CloseMenu->addAction("&Exit Game", this, SLOT(close()));
    //saveAction->setShortcut( QKeySequence::Save );

    QAction* StartAction = StartMenu->addAction("&Start Game", this, SLOT(newGame(scene*)));

    // connect message signal from scene to showMessage slot
    connect(scene, SIGNAL(StartAction), this, SLOT(newGame(Scene*)));

    /* add status bar message
    statusBar()->showMessage("QSimulate has started");*/

  // create scene and central widget view of scene
  scene = new Scene();
  QGraphicsView *view = new QGraphicsView(scene);
  view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
  view->setFrameStyle(0);
  view->setSceneRect(0,0,800,600);
  view->setBackgroundBrush(QBrush(QImage(":/images/bg.png")));
  setCentralWidget(view);

  /*// create an item to add to the scene
  mainship *ship = new mainship();
  ship->setTransformOriginPoint(12.5,12.5);
  ship->setRect(0,0,25,25); // change the rect size
  ship->setPen(QPen(Qt::red, 5));
  QPainter::SmoothPixmapTransform;
  ship->setPos(400,300);*/

  //add the item to the scene
  //scene->addItem(ship);

  /*// make rect focusable
  ship->setFlag(QGraphicsItem::ItemIsFocusable);
  ship->setFocus();*/
}

void MainWindow:: newGame(Scene *scene)
{
    // create an item to add to the scene
    mainship *ship = new mainship();
    ship->setTransformOriginPoint(12.5,12.5);
    ship->setRect(0,0,25,25); // change the rect size
    ship->setPen(QPen(Qt::red, 5));
    QPainter::SmoothPixmapTransform;
    ship->setPos(width()/2,height()/2);

    ship->setFlag(QGraphicsItem::ItemIsFocusable);
    ship->setFocus();

    scene->addItem(ship);
}
