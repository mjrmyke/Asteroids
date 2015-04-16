#include "mainwindow.h"
#include "scene.h"
#include "mainship.h"
#include "bullet.h"
#include "asteroid.h"

#include <QMenuBar>
#include <QGraphicsView>

#include <iostream>

// ADD DESC
MainWindow::MainWindow():QMainWindow()
{
    // add drop down menus
    QMenu* Menu = menuBar()->addMenu("&File");

    QAction* StartAction = Menu->addAction("&Start Game", this, SLOT(StartButton_Clicked()));
    QAction* CloseAction = Menu->addAction("&Exit Game", this, SLOT(close()));


    intro = new Scene();
    /*QGraphicsView *IntroView = new QGraphicsView(intro);
    IntroView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    IntroView->setFrameStyle(0);
    IntroView->setSceneRect(0,0,800,600);
    IntroView->setBackgroundBrush(QBrush(QImage(":/images/intro.png")));
    setCentralWidget(IntroView);*/


    view->setScene(intro);
    view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    view->setFrameStyle(0);
    view->setSceneRect(0,0,800,600);
    view->setBackgroundBrush(QBrush(QImage(":/images/intro.png")));
    setCentralWidget(view);
}

// ADD DESC
void MainWindow::StartButton_Clicked()
{
    // create game scene and initialize game
    game = new Scene();


    /*QGraphicsView *view = new QGraphicsView(scene);
    view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    view->setFrameStyle(0);
    view->setSceneRect(0,0,800,600);
    view->setBackgroundBrush(QBrush(QImage(":/images/bg.png")));
    setCentralWidget(view);*/


    view->setScene(game);
    view->setBackgroundBrush(QBrush(QImage(":/images/bg.png")));


    mainship *ship = new mainship();
    ship->setTransformOriginPoint(7.5,7.5);
    ship->setRect(0,0,15,15); // change the rect size
    ship->setPen(QPen(Qt::red, 2));
    QPainter::SmoothPixmapTransform;
    ship->setPos(width()/2,height()/2);

    ship->setFlag(QGraphicsItem::ItemIsFocusable);
    ship->setFocus();
    game->addItem(ship);

    game->setFocusItem(ship);

    //view->setVisible(true);
    //std::cout<<scene->isActive()<<std::endl;
    //std::cout<<scene->hasFocus()<<std::endl;

    //game->setFocusItem(ship);


    Asteroid *ast = new Asteroid();
    ast->setTransformOriginPoint(25,25);
    ast->setRect(0,0,50,50); // change the rect size
    ast->setPen(QPen(Qt::white, 1));
    QPainter::SmoothPixmapTransform;
    ast->setPos(width()/4,height()/4);

    game->addItem(ast);
}
