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

void MainWindow::spawnAsteroids()
{
    static int seed;
    seed++;
    srand(time(NULL)+seed);
    int i=0;
    Asteroid *ast;
    // spawn asteroids
    for(i; i<3; i++)
    {
        ast = new Asteroid(rand()%3+1);
        ast->setPos(width()-rand()%300+20,height()-rand()%300+20);

        game->addItem(ast);
    }
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == asteroidSpawner.timerId())
    {
        spawnAsteroids();
    }
}



// ADD DESC
void MainWindow::StartButton_Clicked()
{
    asteroidSpawner.stop();
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

    //score label text
    scorelabel = new QGraphicsTextItem("Score:");
    scorelabel->setDefaultTextColor(Qt::white);
    scorelabel->setPos(740,10);
    scorelabel->setScale(2);
    game->addItem(scorelabel);

    //score number text
    int points= 0;
    score = new QGraphicsTextItem(QString::number(points));
    score->setDefaultTextColor(Qt::white);
    score->setPos(840,10);
    score->setScale(2);
    game->addItem(score);

    //link score / score changer for getting hit
    QObject::connect(ship, &mainship::pointsChanged,
                     this, &MainWindow::ScoreChange);


//    QObject::connect(bullet, &Bullet::bulletpointChanged,
//                     this, &MainWindow::ScoreChange);
// this should link the bullet score additions to the score, but it can not identify bullet in line 106


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





    // Start spawning asteroids
    asteroidSpawner.start(15000, this);
    spawnAsteroids();
}

// Updates ship health HUD
void MainWindow::shipShieldHUDUpdate(int shields)
{
//text for death settings
    QGraphicsTextItem* deadtext;

    deadtext = new QGraphicsTextItem("You died, Game Over!");
    deadtext->setDefaultTextColor(Qt::white);
    deadtext->setPos(330,330);
    deadtext->setScale(3);




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
        game->addItem(deadtext);
        break;
    case -1:
        shipShields->setRect(10, 10, 0, 10);
        game->addItem(deadtext);
        break;
    case -2:
        shipShields->setRect(10, 10, 0, 10);
        game->addItem(deadtext);
        break;
    case -3:
        shipShields->setRect(10, 10, 0, 10);
        game->addItem(deadtext);
        break;
    default:
        shipShields->setRect(10, 10, 0, 10);
        break;

    }
}

void MainWindow::ScoreChange(int p)
{
    game->removeItem(score);
    points = points + p;
    score->setPlainText(QString::number(points));
    game->addItem(score);
}
