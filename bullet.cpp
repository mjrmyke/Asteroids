#include "bullet.h"

// Default constructor.
Bullet::Bullet()
{
    // draw the rect

    // size and position
    setRect((10*qCos(angle*(M_PI/180))),(12.55*qSin(angle*(M_PI/180))),5,5);
    setPen(QPen(Qt::green, 1));

    QTransform itTransf = transform();
    QPointF dp = this->boundingRect().center();
    itTransf.translate( dp.x(), dp.y() );
    itTransf.rotate( angle, Qt::ZAxis );
    itTransf *= QTransform::fromScale( scale(), scale() );
    itTransf.translate( -dp.x(), -dp.y() );
    setTransform(itTransf);

    // updates at 60FPS
    timer.start(16.67, this);

    // this broke for some reason
    /*QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(16.67);// 60FPS babyy.*/
}

// Constructs with an angle to enable bullet orientation.
Bullet::Bullet(float angle)
{
    // What do the 10 and 12.55 do?
    setRect((10*qCos(angle*(M_PI/180))), (12.55*qSin(angle*(M_PI/180))),3,1);
    setPen(QPen(Qt::green, 2));

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
void Bullet::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == timer.timerId())
    {
        move();
    }
}

// Updates the bullets position.
void Bullet::move()
{
    // move bullet
    setPos(x()+(5*qCos(angle*(M_PI/180))), y()+(5*qSin(angle*(M_PI/180))));
    if (pos().y() < 0)
    {
        delete this;
    }
}
