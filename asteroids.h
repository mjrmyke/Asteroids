#ifndef ASTEROIDS_H
#define ASTEROIDS_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QBasicTimer>
#include <QTimerEvent>
#include <QPainter>
#include <QtMath>
#include <cmath>

class asteroids: public QObject, public QGraphicsRectItem
{
    Q_OBJECT

private:
    QBasicTimer timer;
    float angle;

protected:
    void timerEvent(QTimerEvent *event);

public:
    asteroids();
    asteroids(float angle);

public slots:
    void move();

};

#endif // ASTEROIDS_H
