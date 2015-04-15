#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QBasicTimer>
#include <QTimerEvent>
#include <QPainter>
#include <QtMath>
#include <cmath>

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
