#include "mainship.h"

// ADD DESC
mainship::mainship()
{
    curAngle = 270;

    timer.start(17, this);

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
    //realize the ship move from one side to the other
    if(x() > 800)
        setPos( x() - 800, y());
    else if(x() < 0)
        setPos( x() + 800, y());

    if(y() > 600)
        setPos( x(),  y() - 600);
    else if(y() < 0)
        setPos( x(), y() + 600);
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
    if (event->key() == Qt::Key_A)
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
    else if (event->key() == Qt::Key_D)
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
    else if (event->key() == Qt::Key_W)
    {
        //  Quick Suggestion by Julian:
        //  we should use a while loop here. While the key is pressed,
        //  increase by 1.0f and set a max speed so we're not all
        //  Portal over here where you constantly build up speed.
        //  If the button is released, you slow overtime, but not by
        //  too much since 0 gravity dictates constant rates of motion
        //  due to lack of friction in space.

        // for momentum conservation
        // add curAngle to momentumAngle and speed for accurate momentum
        fields.addXSpeed(1.0f, curAngle);
        fields.addYSpeed(1.0f, curAngle);
        // for right now
        //setPos(x()+4*qCos(curAngle*3.14/180), y()+4*qSin(curAngle*3.14/180));
    }

    else if (event->key() == Qt::Key_S)
    {
        // for momentum conservation
        fields.addXSpeed(-0.5f, curAngle);
        fields.addYSpeed(-0.5f, curAngle);
        // for right now
        //setPos(x()-2*qCos(curAngle*3.14/180), y()-2*qSin(curAngle*3.14/180));
    }
    else if (event->key() == Qt::Key_Q)
    {
        // for momentum conservation
        if(fields.getXSpeed() >= 0.2f)
        {
            fields.addXSpeed(-0.2f);
        }
        else if(fields.getXSpeed() <= -0.2f)
        {
            fields.addXSpeed(0.2f);
        }
        if(fields.getYSpeed() >= 0.2f)
        {
            fields.addYSpeed(-0.2f);
        }
        else if(fields.getYSpeed() <= -0.2f)
        {
            fields.addYSpeed(0.2f);
        }
        else if(std::abs(fields.getXSpeed()) < 0.2f && std::abs(fields.getYSpeed()) < 0.2f)
        {
            fields.setXSpeed(0.0f);
            fields.setYSpeed(0.0f);
        }
    }
    else if (event->key() == Qt::Key_Space)
    {
        // create a bullet
        Bullet *bullet = new Bullet(curAngle, fields.getXSpeed(), fields.getYSpeed());
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
    }
}
