#include "Bullet.h"
#include <QTimer>
#include <QgraphicsItem>
#include <QPainter>
#include <QtMath>

Bullet::Bullet(){
    // drew the rect
    setRect(10,12.5,5,10);
    setPen(QPen(Qt::green, 5));

    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move(){
    // move bullet up
    setPos(x(),y()-10);

    if (pos().y() < 0){
        delete this;
    }
}
