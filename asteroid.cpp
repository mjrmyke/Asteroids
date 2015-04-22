#include "asteroid.h"
#include <QGraphicsScene>
#include <typeinfo>

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

Asteroid::Asteroid(int size)
{
    fields.setXSpeed(3);
    fields.setYSpeed(0);
    if (size == 3)
    {
       this->size = 3;
       setRect(0, 0, 60, 60);
       setPen(QPen(Qt::white, 1));

       health = 10;
    }

    if (size == 2)
    {
       this->size = 2;
       setRect(0, 0, 30, 30);
       setPen(QPen(Qt::white, 1));

       health = 5;
    }

    if (size == 1)
    {
       this->size = 1;
       setRect(0, 0, 15, 15);
       setPen(QPen(Qt::white, 1));

       health = 2;
    }

    // start the timer. 16.67ms = 60FPS
    timer.start(16.67, this);
}

//Asteroid health
int Asteroid::getHealth() const
{
    return health;
}

void Asteroid::setHealth(int value)
{
    health = value;
}

void Asteroid::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == timer.timerId())
    {
        move();
    }
}

// Updates the Asteroid position
void Asteroid::move()
{
    // move asteroid
    // MANUALLY SET TO 0 DEGREES FOR TIME BEING
    setPos(x()+fields.getXSpeed(), y()+fields.getYSpeed());
    if (pos().y() < 0)
    {
        delete this;
    }
    // screen looping
    if(x() > 960)
        setPos( x() - 960, y());
    else if(x() < 0)
        setPos( x() + 960, y());

    if(y() > 720)
        setPos( x(),  y() - 720);
    else if(y() < 0)
        setPos( x(), y() + 720);

    if(health <= 0)
    {
        this->death();
        delete this;
    }
}

//the asteroids dire fate
void Asteroid::death()
{
    if (this->size == 3)
    {
        Asteroid * mAsteroid1 = new Asteroid(2);
        mAsteroid1->fields.addXSpeed(1, 45);
        mAsteroid1->fields.addYSpeed(1, 45);
        mAsteroid1->setPos(x(),y());
        Asteroid * mAsteroid2 = new Asteroid(2);
        mAsteroid2->fields.addXSpeed(1, 15);
        mAsteroid2->fields.addYSpeed(1, 15);
        mAsteroid2->setPos(x(),y());

        scene()->addItem(mAsteroid1);
        scene()->addItem(mAsteroid2);
    }

    else if (this->size == 2)
    {
        Asteroid * sAsteroid1 = new Asteroid(1);
        sAsteroid1->fields.addXSpeed(1, 45);
        sAsteroid1->fields.addYSpeed(1, 45);
        sAsteroid1->setPos(x(),y());
        Asteroid * sAsteroid2 = new Asteroid(1);
        sAsteroid2->fields.addXSpeed(1, 20);
        sAsteroid2->fields.addYSpeed(1, 20);
        sAsteroid2->setPos(x(),y());
        Asteroid * sAsteroid3 = new Asteroid(1);
        sAsteroid3->fields.addXSpeed(1, 80);
        sAsteroid3->fields.addYSpeed(1, 80);
        sAsteroid3->setPos(x(),y());

        scene()->addItem(sAsteroid1);
        scene()->addItem(sAsteroid2);
        scene()->addItem(sAsteroid3);
    }

    //else if (this->size = 1)

}
