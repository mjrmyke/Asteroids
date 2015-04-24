#include "mainwindow.h"
#include "scene.h"
#include "mainship.h"
#include "bullet.h"
#include "asteroid.h"
#include <QMediaPlayer>
#include <QMenuBar>


// ADD DESC
MainWindow::MainWindow():QMainWindow()
{
    // add drop down menus
    QMenu* fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction("&Start Game", this, SLOT(StartButton_Clicked()));
    fileMenu->addAction("&Exit Game", this, SLOT(close()));

    // initialize intro screen
    view = new QGraphicsView;

    intro = new Scene();

    view->setScene(intro);
    view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    view->setFrameStyle(0);
    view->setSceneRect(0,0,960,720);
    view->setBackgroundBrush(QBrush(QImage(":/images/intro.png")));

    setCentralWidget(view);

    //Intro Music
    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/intromusic.mp3"));
    music->play();

}

// ADD DESC
void MainWindow::StartButton_Clicked()
{
    // create game scene and initialize game
    game = new Scene();
    game->setStickyFocus(true);// player cannot deselect ship
    music->stop();  //stops old music (intro or game)

    //sets game music, in the case it came from the intro
    music->setMedia(QUrl("qrc:/sounds/gamemusic.mp3"));
    music->play();  //plays music


    view->setScene(game);
    view->setBackgroundBrush(QBrush(QImage(":/images/bg.png")));


    //spawn player (ship)
    mainship *ship = new mainship();
    ship->setTransformOriginPoint(30,20);
    ship->setPixmap(QPixmap(":/images/ship.png"));
    ship->setPos(width()/2,height()/2);
    ship->setFlag(QGraphicsItem::ItemIsFocusable);
    ship->setTransformationMode(Qt::SmoothTransformation);

    game->addItem(ship);
    ship->setFocus();


    // spawn asteroids
    Asteroid *ast3 = new Asteroid(3);
    ast3->setPos(width()/4,height()/4);
    Asteroid *ast2 = new Asteroid(2);
    ast2->setPos(width()/6,height()/6);
    Asteroid *ast1 = new Asteroid(1);
    ast1->setPos(width()/3,height()/3);

    game->addItem(ast3);
    game->addItem(ast2);
    game->addItem(ast1);
}
