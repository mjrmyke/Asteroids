#include "myship.h"
#include "bullet.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>


void myship::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        QTransform itTransf = transform();
              QPointF dp = this->boundingRect().center();

              itTransf.translate( dp.x(), dp.y());
              itTransf.rotate( rotation() - 5, Qt::ZAxis);
              itTransf *= QTransform::fromScale( scale(), scale());
              itTransf.translate( -dp.x(),  -dp.y());

              setTransform(itTransf);
    }
    else if (event->key() == Qt::Key_Right){
        QTransform itTransf = transform();
              QPointF dp = this->boundingRect().center();

              itTransf.translate( dp.x(), dp.y());
              itTransf.rotate( rotation() + 5, Qt::ZAxis);
              itTransf *= QTransform::fromScale( scale(), scale());
              itTransf.translate( -dp.x(),  -dp.y());

              setTransform(itTransf);
    }
    else if (event->key() == Qt::Key_Up){
        setPos(x(),y()-5);
    }
    else if (event->key() == Qt::Key_Down){
        setPos(x(),y()+5);
    }
    else if (event->key() == Qt::Key_Space){
        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
    }
}

qreal myship::angle(qreal &degree)
{
    degree = rotation();
    return degree;
}





