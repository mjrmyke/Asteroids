#include "bullet.h"

// Default constructor.
Bullet::Bullet()
{
    // draw the rect

    // size and position
    setRect((10*qCos(angle*(M_PI/180))),(12.55*qSin(angle*(M_PI/180))),5,1);
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

// Constructs with an angle and speed to enable realistic bullet firing.
Bullet::Bullet(float angle, float speedX, float speedY)
{
    // What do the 10 and 12.55 do?
    setRect((10*qCos(angle*(M_PI/180))), (12.55*qSin(angle*(M_PI/180))),5,1);
    setPen(QPen(Qt::green, 1));

    // rotates bullet
    this->angle = angle;
    QTransform itTransf = transform();
    QPointF dp = this->boundingRect().center();
    itTransf.translate( dp.x(), dp.y() );
    itTransf.rotate( angle, Qt::ZAxis );
    itTransf *= QTransform::fromScale( scale(), scale() );
    itTransf.translate( -dp.x(), -dp.y() );
    setTransform(itTransf);

    // sets initial speeds
    this->initSpeedX = speedX;
    this->initSpeedY = speedY;

    // start the timer. 16.67ms = 60FPS
    timer.start(16.67, this);
    // start the despawn timer (3 seconds).
    timeout.start(3000, this);
}

// Fires whenever the timer fires.
void Bullet::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == timer.timerId())
    {
        move();
    }
    if (event->timerId() == timeout.timerId())
    {
        despawn();
    }
}

// Updates the bullets position.
void Bullet::move()
{
    // move bullet
    setPos( x() + initSpeedX/2 + (20*qCos(angle*(M_PI/180) )) ,
            y() + initSpeedY/2 + (20*qSin(angle*(M_PI/180) )) );
    // screen looping
    if(x() > 800)
        setPos( x() - 800, y());
    else if(x() < 0)
        setPos( x() + 800, y());

    if(y() > 600)
        setPos( x(),  y() - 600);
    else if(y() < 0)
        setPos( x(), y() + 600);
}

// Despawns the bullet when its time has come.
void Bullet::despawn()
{
    delete this;
}
