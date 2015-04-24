#include "mainship.h"

// Default constructor.
mainship::mainship()
{
    // face up
    curAngle = 270;
    // start timer (60 FPS)
    timer.start(17, this);
}


// Updates the ship's position and velocity
void mainship::move()
{
    // move ship
    setPos(x()+fields.getXSpeed(), y()+fields.getYSpeed());

    // screen looping
    if(x() > 960)
        setPos( x() - 960, y());
    else if(x() < 0)
        setPos( x() + 960, y());

    if(y() > 720)
        setPos( x(),  y() - 720);
    else if(y() < 0)
        setPos( x(), y() + 720);
}


// Fires whenever the timer fires.
void mainship::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == timer.timerId())
    {
        // handles key presses
        foreach(Qt::Key k, keysPressed)
        {
           switch(k)
           {
           case Qt::Key_W:
           {
               // add curAngle to momentumAngle and speed for accurate momentum
               fields.addXSpeed(0.2f, curAngle);
               fields.addYSpeed(0.2f, curAngle);
               break;
           }

           case Qt::Key_S:
           {
               // add curAngle to momentumAngle and speed for accurate momentum
               fields.addXSpeed(-0.1f, curAngle);
               fields.addYSpeed(-0.1f, curAngle);
               break;
           }

           case Qt::Key_A:
           {
               QTransform itTransf = transform();
               QPointF dp = this->boundingRect().center();
               itTransf.translate( dp.x(), dp.y() );
               itTransf.rotate( rotation()-5, Qt::ZAxis );
               curAngle -= 5;// store rotation values
               // ensure 0<=curAngle<360
               if(curAngle >= 360){curAngle = 360%static_cast<int>(curAngle);}
               if(curAngle < 0){curAngle = 360+curAngle;}
               itTransf *= QTransform::fromScale( scale(), scale() );
               itTransf.translate( -dp.x(), -dp.y() );
               setTransform(itTransf);
               break;
           }

           case Qt::Key_D:
           {
               QTransform itTransf = transform();
               QPointF dp = this->boundingRect().center();
               itTransf.translate( dp.x(), dp.y() );
               itTransf.rotate( rotation()+5, Qt::ZAxis );
               curAngle += 5;// store rotation values
               // ensure 0<=curAngle<360
               if(curAngle >= 360){curAngle = 360%static_cast<int>(curAngle);}
               if(curAngle < 0){curAngle = 360+curAngle;}
               itTransf *= QTransform::fromScale( scale(), scale() );
               itTransf.translate( -dp.x(), -dp.y() );
               setTransform(itTransf);
               break;
           }

           case Qt::Key_Q:
           {
               // soft brake
               if(fields.getXSpeed() >= 0.05f)
               {
                   fields.addXSpeed(-0.05f);
               }
               else if(fields.getXSpeed() <= -0.05f)
               {
                   fields.addXSpeed(0.05f);
               }
               if(fields.getYSpeed() >= 0.05f)
               {
                   fields.addYSpeed(-0.05f);
               }
               else if(fields.getYSpeed() <= -0.05f)
               {
                   fields.addYSpeed(0.05f);
               }
               else if(std::abs(fields.getXSpeed()) < 0.05f && std::abs(fields.getYSpeed()) < 0.05f)
               {
                   fields.setXSpeed(0.0f);
                   fields.setYSpeed(0.0f);
               }
               break;
           }

           case Qt::Key_Space:
           {
               // BULLETS FIRE TOO FAST JULIAN! TOO FAST!
               // create a bullet
               Bullet *bullet = new Bullet(curAngle, fields.getXSpeed(), fields.getYSpeed());
               bullet->setPos(x(),y());
               scene()->addItem(bullet);
           }

           default:
           {
               // prevents 435 warnings
               break;
           }
           }
        }

        // update velocity
        move();
    }
}


// Adds currently held keys to the QSet container.
void mainship::keyPressEvent(QKeyEvent *event)
{
    keysPressed += (Qt::Key)event->key();
}


// Removes currently unheld keys to the QSet container.
void mainship::keyReleaseEvent(QKeyEvent *event)
{
    keysPressed -= (Qt::Key)event->key();
}
