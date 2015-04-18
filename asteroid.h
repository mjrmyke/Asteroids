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
    int health;
    QBasicTimer timer;
    float angle;

protected:
    void timerEvent(QTimerEvent *event);

public:
    Asteroid();
    Asteroid(float angle);

    int getHealth() const;
    void setHealth(int value);

public slots:
    void move();

};

#endif // Asteroid_H
