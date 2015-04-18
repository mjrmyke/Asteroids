#include "asteroid.h"

// Default constructor
Asteroid::Asteroid()
{

    /* maybe make 2 additional asteroid constructors for big, medium, and small to
     * make stuff easier.*/

    /* Work on making big asteroids split into 2 medium ones and making medium
     * asteroids split into 3 small ones, with appropriate health*/


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

Asteroid::Asteroid(float angle)
{
    // What do the 10 and 12.55 do?
    setRect((10*qCos(angle*(M_PI/180))), (12.55*qSin(angle*(M_PI/180))),3,1);
    setPen(QPen(Qt::white, 1));

    // rotates bullet
    this->angle = angle;
    QTransform itTransf = transform();
    QPointF dp = this->boundingRect().center();
    itTransf.translate( dp.x(), dp.y() );
    itTransf.rotate( angle, Qt::ZAxis );
    itTransf *= QTransform::fromScale( scale(), scale() );
    itTransf.translate( -dp.x(), -dp.y() );
    setTransform(itTransf);

    health = 10;

    // start the timer. 16.67ms = 60FPS
    timer.start(16.67, this);
}

// Fires whenever the timer fires.

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
    setPos(x()+(1*qCos(0*(M_PI/180))), y()+(1*qSin(0*(M_PI/180))));
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
        delete this;
    }
}
