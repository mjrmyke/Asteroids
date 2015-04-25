#include "mainwindow.h"

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
    ship = new mainship();
    ship->setTransformOriginPoint(30,20);
    ship->setPixmap(QPixmap(":/images/ship.png"));
    ship->setPos(width()/2,height()/2);
    ship->setFlag(QGraphicsItem::ItemIsFocusable);
    ship->setTransformationMode(Qt::SmoothTransformation);
    game->addItem(ship);
    ship->setFocus();

    // creates ship health bar
    shipShields = new QGraphicsRectItem();
    shipShields->setRect(10, 10, width()/4, 10);
    shipShields->setZValue(2);
    shipShields->setBrush(QBrush(Qt::cyan));
    shipShields->setOpacity(0.5);
    game->addItem(shipShields);
    // make the health bar update when the ship emits signal
    QObject::connect(ship, &mainship::shieldsChanged,
                     this, &MainWindow::shipShieldHUDUpdate);

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

// Updates ship health HUD
void MainWindow::shipShieldHUDUpdate(int shields)
{
    switch(shields)
    {
    case 6:
        shipShields->setRect(10, 10, 240, 10);
        shipShields->setBrush(QBrush(Qt::cyan));
        break;

    case 5:
        shipShields->setRect(10, 10, 200, 10);
        shipShields->setBrush(QBrush(Qt::green));
        break;

    case 4:
        shipShields->setRect(10, 10, 160, 10);
        shipShields->setBrush(QBrush(Qt::green));
        break;

    case 3:
        shipShields->setRect(10, 10, 120, 10);
        shipShields->setBrush(QBrush(Qt::yellow));
        break;

    case 2:
        shipShields->setRect(10, 10, 80, 10);
        shipShields->setBrush(QBrush(Qt::yellow));
        break;

    case 1:
        shipShields->setRect(10, 10, 40, 10);
        shipShields->setBrush(QBrush(Qt::red));
        break;

    case 0:
        shipShields->setRect(10, 10, 0, 10);
        break;

    default:
        break;

    }
}
