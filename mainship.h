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
#include <QSet>

class mainship: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    // Container for processing and storing position and velocity data.
    updatePos fields;
    // Container for ship's current heading.
    float curAngle;
    // The ship's timer.
    QBasicTimer timer;
    // Container for key presses, prevents duplicates.
    QSet<Qt::Key> keysPressed;
    // Handles key presses.
    void keys();

public:
    // Default constructor.
    mainship();
    // Adds currently held keys to the QSet container.
    void keyPressEvent(QKeyEvent *event);
    // Removes currently unheld keys to the QSet container.
    void keyReleaseEvent(QKeyEvent *event);


protected:
    // Fires whenever the timer fires.
    void timerEvent(QTimerEvent *event);

public slots:
    // Updates the ship's position and velocity
    void move();

};

#endif
