#include "bullet.h"
#include <iostream>

Bullet::Bullet()
{
    std::cout<<"angle"<<angle2<<"\n";
    // draw the rect

    // size and position
    setRect((10*qCos(angle2*(M_PI/180))),(12.55*qSin(angle2*(M_PI/180))),5,10);
    setPen(QPen(Qt::green, 1));

    rotate();

    // updates at 60FPS
    timer.start(16.67, this);

    // this broke for some reason
    /*// connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(16.67);// 60FPS babyy.*/
}

Bullet::Bullet(float angle)
{
    std::cout<<"angle"<<angle2<<"\n";

    setRect((10*qCos(angle2*(M_PI/180))),(12.55*qSin(angle2*(M_PI/180))),5,2);
    setPen(QPen(Qt::green, 1));

    this->angle2 = angle;
    rotate();

    timer.start(16.67, this);
}

void Bullet::setAngle2(float a)
{
    angle2 = a;
}

void Bullet::rotate()
{
    QTransform itTransf = transform();
    QPointF dp = this->boundingRect().center();
    itTransf.translate( dp.x(), dp.y() );
    itTransf.rotate( angle2, Qt::ZAxis );
    itTransf *= QTransform::fromScale( scale(), scale() );
    itTransf.translate( -dp.x(), -dp.y() );
    setTransform(itTransf);
}

void Bullet::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == timer.timerId())
    {
        move();
    }
}

void Bullet::move()
{
    // move bullet
    setPos(x()+(6*qCos(angle2*(M_PI/180))), y()+(6*qSin(angle2*(M_PI/180))));
    if (pos().y() < 0)
    {
        delete this;
    }
}
