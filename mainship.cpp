#include "mainship.h"

// ADD DESC
mainship::mainship()
{
    curAngle = 0;

    timer.start(16.67, this);

    /* WHY THE HELL WON'T THIS WORK!?
    QTimer * timer2 = new QTimer();
    //QObject::connect(timer2,(SIGNAL(timeout()),this,SLOT(updatePos())));
    QObject::connect(this, SIGNAL(timeout()), SLOT(updatePos()));
    timer2->start(16.67);// 60FPS babyy.*/
}

// ADD DESC
void mainship::move()
{
    setPos(x()+fields.getXSpeed(), y()+fields.getYSpeed());
}

// Fires whenever the timer fires.
void mainship::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == timer.timerId())
    {
        move();
    }
}

// ADD DESC
void mainship::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {
        QTransform itTransf = transform();
        QPointF dp = this->boundingRect().center();
        itTransf.translate( dp.x(), dp.y() );
        itTransf.rotate( rotation()-10, Qt::ZAxis );
        curAngle -= 10;// store rotation values
        // ensure 0<=curAngle<360
        if(curAngle >= 360){curAngle = 360%static_cast<int>(curAngle);}
        if(curAngle < 0){curAngle = 360+curAngle;}
        itTransf *= QTransform::fromScale( scale(), scale() );
        itTransf.translate( -dp.x(), -dp.y() );
        setTransform(itTransf);
    }
    else if (event->key() == Qt::Key_Right)
    {
        QTransform itTransf = transform();
        QPointF dp = this->boundingRect().center();
        itTransf.translate( dp.x(), dp.y() );
        itTransf.rotate( rotation()+10, Qt::ZAxis );
        curAngle += 10;// store rotation values
        // ensure 0<=curAngle<360
        if(curAngle >= 360){curAngle = 360%static_cast<int>(curAngle);}
        if(curAngle < 0){curAngle = 360+curAngle;}
        itTransf *= QTransform::fromScale( scale(), scale() );
        itTransf.translate( -dp.x(), -dp.y() );
        setTransform(itTransf);
    }
    else if (event->key() == Qt::Key_Up)
    {
        // for momentum conservation
        // add curAngle to momentumAngle and speed for accurate momentum
        fields.setXSpeed(1, curAngle);
        fields.setYSpeed(1, curAngle);
        // for right now
        //setPos(x()+4*qCos(curAngle*3.14/180), y()+4*qSin(curAngle*3.14/180));
    }
    else if (event->key() == Qt::Key_Down)
    {
        // for momentum conservation
        fields.setXSpeed(-0.5, curAngle);
        fields.setYSpeed(-0.5, curAngle);
        // for right now
        //setPos(x()-2*qCos(curAngle*3.14/180), y()-2*qSin(curAngle*3.14/180));
    }
    else if (event->key() == Qt::Key_Space)
    {
        // create a bullet
        Bullet *bullet = new Bullet(curAngle);
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
    }
}
