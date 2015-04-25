#ifndef Asteroid_H
#define Asteroid_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QBasicTimer>
#include <QTimerEvent>
#include <QPainter>
#include <QtMath>
#include <cmath>
#include "updatepos.h"

class Asteroid: public QObject, public QGraphicsRectItem
{
    Q_OBJECT

private:
    int health;
    updatePos fields;
    QBasicTimer timer;
    float angle;
    int size;

protected:
    void timerEvent(QTimerEvent *event);

public:
    Asteroid();
    Asteroid(int size);
    void death();
    int getHealth() const;
    void setHealth(int value);
    // Getters/Setters.
    int getSize() const;
    void setSize(int value);

public slots:
    void move();

};

#endif // Asteroid_H
