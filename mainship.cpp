#include "mainship.h"

// Default constructor.
mainship::mainship()
{
    // face up
    curAngle = 270;
    // prevents weirdness on MinGW
    fields.setXSpeed(0);
    fields.setYSpeed(0);
    // set the overheat and the canFire variables
    overheated = false;
    canFire = true;
    //  heat iterator
    heat = 0.0f;
    // shields
    shield = 6;

    // start timer (60 FPS)
    timer.start(17, this);
}


// Updates the ship's position and velocity
void mainship::move()
{
    bool hit = false;
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

    // collision detection
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i=0, n=colliding_items.size(); i<n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Asteroid))
        {
            // destroy asteroid for giggles
            static_cast<Asteroid *>(colliding_items[i])->setHealth(0);

            // reduce ship's shields depending on size of asteroid
            switch(static_cast<Asteroid *>(colliding_items[i])->getSize())
            {
            case 3:
                shield-=3;
                break;

            case 2:
                shield-=2;
                break;
            case 1:
                shield-=1;

            default:
                break;
            }

            // send signal for hud update
            shieldsChanged(shield);

            // kill ship if dead
            if(shield <= 0)
            {
                // remove ship from scene
                this->scene()->removeItem(this);

                // flag ship for deletion
                hit = true;
            }
        }
        if(hit)
        {
            delete this;
            break;
        }
    }
}//mainship::move


// Handles key presses.
void mainship::keys()
{
    foreach(Qt::Key k, keysPressed)
    {
       switch(k)
       {
       case Qt::Key_Up:
       case Qt::Key_W:
       {
           // add curAngle to momentumAngle and speed for accurate momentum
           fields.addXSpeed(0.3f, curAngle);
           fields.addYSpeed(0.3f, curAngle);
           break;
       }

       case Qt::Key_Down:
       case Qt::Key_S:
       {
           // add curAngle to momentumAngle and speed for accurate momentum
           fields.addXSpeed(-0.15f, curAngle);
           fields.addYSpeed(-0.15f, curAngle);
           break;
       }

       case Qt::Key_Left:
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

       case Qt::Key_Right:
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

       case Qt::Key_Shift:
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
           // create a bullet
           if (canFire)
           {
               Bullet *bullet = new Bullet(curAngle, fields.getXSpeed(), fields.getYSpeed());
               bullet->setPos(x(),y());
               scene()->addItem(bullet);
               // limits fire rate to 3 RPS
               fireRate.start(333, this);
               canFire = false;
           }
       }
       default:
       {
           // prevents 430 warnings
           break;
       }
       }
    }
}


// Fires whenever the timer fires.
void mainship::timerEvent(QTimerEvent *event)
{
    // main timer
    if (event->timerId() == timer.timerId())
    {
        // handle key presses
        keys();
        // update position
        move();
    }
    // fire rate timer
    if (event->timerId() == fireRate.timerId())
    {
        fireRate.stop();
        canFire = true;
    }
}


// Emits signal when hurt.
void shieldsChanged(int newValue)
{
    emit newValue;
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
