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
    // Fire rate limiter for bullets
    QBasicTimer fireRate;
    // Container for key presses, prevents duplicates.
    QSet<Qt::Key> keysPressed;
    // Handles key presses.
    void keys();
    // error checking for fire limiter
    bool overheated, canFire;
    // fire ability bar data. from 0 to 1. If it's 1, it will kick overheated to 'true'. If it's true, heat will decrease by 0.1f
    // and the player will not be able to fire until the heat = 0.
    float heat;
    // define the shields. should be a power up later, but we'll implement it now to make sure it works
    int shield;//adds shields
    // sfx
    QMediaPlayer *sfx;

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

signals:
    void shieldsChanged(int);
    //void pointsChanged(int newpoint);


public slots:
    // Updates the ship's position and velocity
    void move();

};

#endif
