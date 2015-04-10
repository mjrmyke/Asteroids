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
    void rotate();
    float angle2;

protected:
    void timerEvent(QTimerEvent *event);

public:
    Bullet();
    Bullet(float angle);
    double angle;
    void setAngle2(float a);

public slots:
    void move();

};

#endif // BULLET_H
