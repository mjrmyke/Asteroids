#ifndef mainship_h
#define mainship_h

#include "bullet.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QtMath>

#include <iostream>
#include <QTimer>

#include <QGraphicsItem>
#include <QObject>
#include <QMainWindow>

class mainship: /*public QObject,*/ public QGraphicsRectItem
{
    //Q_OBJECT

public:
    //mainship();
    void keyPressEvent(QKeyEvent * event);
    float theta;
    float velocity;

//public slots:
    //void updatePos();

};

#endif
