#include "bullet.h"
#include <QTimer>
#include <QGraphicsItem>
#include <QPainter>
#include <QtMath>

Bullet::Bullet(){
    // draw the rect
    setRect((10*qCos(angle*(3.14/180))),(12.55*qSin(angle*(3.14/180))),5,10);
    setPen(QPen(Qt::green, 5));


    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Bullet::move(){
    // move bullet up
    setPos(x()+(5*qCos(angle*(3.14/180))),y()+(5*qSin(angle*(3.14/180))));
    if (pos().y() < 0)
    {
        delete this;
    }
}
