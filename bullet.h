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

enum weaponType {

};

class Bullet: public QObject, public QGraphicsRectItem
{
    Q_OBJECT

private:
    // Frame timer.
    QBasicTimer timer;
    // Despawn timer.
    QBasicTimer timeout;
    // Local angle container.
    float angle;
    // Initial speed containers.
    float initSpeedX;
    float initSpeedY;

protected:
    // Fires whenever the timers fire.
    void timerEvent(QTimerEvent *event);

public:
    // Default constructor.
    Bullet();
    // Constructs with an angle and speed to enable realistic bullet firing.
    Bullet(float angle, float speedX, float speedY);

public slots:
    // Handles what the bullet should do every frame.
    void update();
    // Deletes bullet when its time has come.
    void despawn();

};

#endif // BULLET_H
