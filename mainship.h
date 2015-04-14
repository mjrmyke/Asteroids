#ifndef mainship_h
#define mainship_h

#include "bullet.h"
#include "updatepos.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QtMath>

#include <cmath>

#include <iostream>
#include <QTimer>

#include <QGraphicsItem>
#include <QObject>
#include <QMainWindow>

#include <QBasicTimer>
#include <QTimerEvent>

class mainship: public QObject, public QGraphicsRectItem
{
    Q_OBJECT

private:
    updatePos fields;
    float curAngle;
    QBasicTimer timer;

public:
    mainship();
    void keyPressEvent(QKeyEvent *event);


protected:
    void timerEvent(QTimerEvent *event);

public slots:
    void move();

};

#endif
