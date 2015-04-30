#include "asteroid.h"
#include <QGraphicsScene>
#include <typeinfo>
#include <stdlib.h>
#include <time.h>
#include <iostream>

// Default constructor
Asteroid::Asteroid()
{
    // size and position
    setRect((10*qCos(angle*(M_PI/180))),(12.55*qSin(angle*(M_PI/180))),5,5);
    setPen(QPen(Qt::white, 1));

    QTransform itTransf = transform();
    QPointF dp = this->boundingRect().center();
    itTransf.translate( dp.x(), dp.y() );
    //itTransf.rotate( angle, Qt::ZAxis );
    itTransf *= QTransform::fromScale( scale(), scale() );
    itTransf.translate( -dp.x(), -dp.y() );
    setTransform(itTransf);

    health = 10;

    // updates at 60FPS
    timer.start(16.67, this);
}

// generates a random float between -1 and 2.
float frng()
{
    static int seed;
    int neg = 1;
    seed++;
    srand(time(NULL)+seed);
    neg = rand()%2;
    if(neg == 0)
        return (rand()%10+10)/10.0f;
    else
        return -1*(rand()%10+10)/10.0f;
}

// generates a random degree
int drng()
{
    static int seed;
    seed++;
    srand(time(NULL)+seed);
    return rand()%360+1;
}

Asteroid::Asteroid(int size)
{
    canCollide = false;
    iFrames.start(200, this);
    fields.addXSpeed(frng(),drng());
    fields.addYSpeed(frng(),drng());

    switch (size)
    {
    case 3:
       this->size = 3;
       setRect(0, 0, 60, 60);
       setPen(QPen(Qt::white, 1));
       health = 10;
       break;

    case 2:
       this->size = 2;
       setRect(0, 0, 30, 30);
       setPen(QPen(Qt::white, 1));
       health = 5;
       break;

    case 1:
       this->size = 1;
       setRect(0, 0, 15, 15);
       setPen(QPen(Qt::white, 1));
       health = 2;
       break;
    }
    // start the timer. 16.67ms = 60FPS
    timer.start(16.67, this);
}

// Gets asteroid's health
int Asteroid::getHealth() const
{
    return health;
}

// Sets asteroid's health
void Asteroid::setHealth(int value)
{
    health = value;
}


// Gets asteroid's size.
int Asteroid::getSize() const
{
    return size;
}


// Sets asteroid's size.
void Asteroid::setSize(int value)
{
    size = value;
}



updatePos Asteroid::getFields() const
{
    return fields;
}

void Asteroid::setFields(const updatePos &value)
{
    fields = value;
}

bool Asteroid::getCanCollide() const
{
    return canCollide;
}

void Asteroid::setCanCollide(bool value)
{
    canCollide = value;
}
void Asteroid::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == timer.timerId())
    {
        move();
    }
    if (event->timerId() == iFrames.timerId())
    {
        iFrames.stop();
        canCollide = true;
    }
}

// Updates the Asteroid position
void Asteroid::move()
{
    // move asteroid
    setPos(x()+fields.getXSpeed(), y()+fields.getYSpeed());

    // screen looping
    if(x() > 960)
        setPos( x() - 960, y());
    else if(x() < 0)
        setPos( x() + 960, y());

    if(y() > 720)
        setPos( x(),  y() - 720);
    else if(y() < 0)
        setPos( x(), y() + 720);

    // handles death

    if(health <= 0)
    {
        this->death();
        delete this;
    }
}

// the asteroids dire fate
void Asteroid::death()
{
    srand(time(NULL));
    switch (size)
    {
    case 3:
    {
        Asteroid * mAsteroid1 = new Asteroid(2);
        mAsteroid1->fields.addXSpeed(frng(), drng());
        mAsteroid1->fields.addYSpeed(frng(), drng());
        mAsteroid1->setPos(x(),y());

        Asteroid * mAsteroid2 = new Asteroid(2);
        mAsteroid2->fields.addXSpeed(frng(), drng());
        mAsteroid2->fields.addYSpeed(frng(), drng());
        mAsteroid2->setPos(x()+30,y()+30);

        scene()->addItem(mAsteroid1);
        scene()->addItem(mAsteroid2);
        break;
    }
    case 2:
    {


        Asteroid * sAsteroid1 = new Asteroid(1);
        sAsteroid1->fields.addXSpeed(frng(), drng());
        sAsteroid1->fields.addYSpeed(frng(), drng());
        sAsteroid1->setPos(x(),y());

        Asteroid * sAsteroid2 = new Asteroid(1);
        sAsteroid2->fields.addXSpeed(frng(), drng());
        sAsteroid2->fields.addYSpeed(frng(), drng());
        sAsteroid2->setPos(x()+15,y()+15);

        scene()->addItem(sAsteroid1);
        scene()->addItem(sAsteroid2);
        break;
    }
    }
}
