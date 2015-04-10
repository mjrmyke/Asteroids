#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QBasicTimer>
#include <QTimerEvent>

#include <QTimer>
#include <QGraphicsItem>
#include <QPainter>
#include <QtMath>
#include <cmath>

class Bullet: public QObject, public QGraphicsRectItem
{
    Q_OBJECT

private:
    QBasicTimer timer;
    float angle;

protected:
    void timerEvent(QTimerEvent *event);

public:
    Bullet();
    Bullet(float angle);

public slots:
    void move();

};

#endif // BULLET_H
