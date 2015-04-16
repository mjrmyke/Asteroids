#ifndef Asteroid_H
#define Asteroid_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QBasicTimer>
#include <QTimerEvent>
#include <QPainter>
#include <QtMath>
#include <cmath>

class Asteroid: public QObject, public QGraphicsRectItem
{
    Q_OBJECT

private:
    QBasicTimer timer;
    float angle;

protected:
    void timerEvent(QTimerEvent *event);

public:
    Asteroid();
    Asteroid(float angle);

public slots:
    void move();

};

#endif // Asteroid_H
