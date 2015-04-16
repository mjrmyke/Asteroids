#include "asteroid.h"

// Default constructor
Asteroid::Asteroid()
{

    // TRY QGraphicsItem

/*
    QPainter painter(this);

    // make the polygon
    QPolygon poly;
    poly << QPoint(90,100);
    poly << QPoint(24,60);
    poly << QPoint(10,70);
    poly << QPoint(50,110);

    // make a pen
    QPen linepen;
    linepen.setWidth(8);
    linepen.setColor(Qt::white);

    painter.setPen(linepen);

    // draw the polygon
    painter.drawPolygon(poly);
*/


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

    // start the timer. 16.67ms = 60FPS
    timer.start(16.67, this);
}

// Fires whenever the timer fires.
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
}
