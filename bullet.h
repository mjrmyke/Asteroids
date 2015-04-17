#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QBasicTimer>
#include <QTimerEvent>
#include <QPainter>
#include <QtMath>
#include <cmath>
#include <QList>
#include <typeinfo>
#include <QGraphicsScene>
#include "asteroid.h"

class Bullet: public QObject, public QGraphicsRectItem
{
    Q_OBJECT

private:
    QBasicTimer timer;
    QBasicTimer timeout;
    float angle;
    float initSpeedX;
    float initSpeedY;

protected:
    void timerEvent(QTimerEvent *event);

public:
    Bullet();
    Bullet(float angle, float speedX, float speedY);

public slots:
    void move();
    void despawn();

};

#endif // BULLET_H
