#include "mainship.h"

// ADD DESC
/*mainship::mainship()
{
    theta = 135;
    velocity = 0;
    // connect
    // WHY THE HELL WON'T THIS WORK!
    QTimer * timer2 = new QTimer();
    //QObject::connect(timer2,(SIGNAL(timeout()),this,SLOT(updatePos())));
    QObject::connect(this, SIGNAL(timeout()), SLOT(updatePos()));
    timer2->start(16.67);// 60FPS babyy.
}

// ADD DESC
void mainship::updatePos()
{
    setPos(x()+velocity*qCos(theta), y()+velocity*qSin(theta));
}*/

// ADD DESC
void mainship::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {
        QTransform itTransf = transform();
        QPointF dp = this->boundingRect().center();
        itTransf.translate( dp.x(), dp.y() );
        itTransf.rotate( rotation()-5, Qt::ZAxis );
        theta -= 5;// store rotation values
        // ensure 0<=theta<360
        if(theta >= 360){theta = 360%static_cast<int>(theta);}
        if(theta < 0){theta = 360+theta;}
        itTransf *= QTransform::fromScale( scale(), scale() );
        itTransf.translate( -dp.x(), -dp.y() );
        setTransform(itTransf);
    }
    else if (event->key() == Qt::Key_Right)
    {
        QTransform itTransf = transform();
        QPointF dp = this->boundingRect().center();
        itTransf.translate( dp.x(), dp.y() );
        itTransf.rotate( rotation()+5, Qt::ZAxis );
        theta += 5;// store rotation values
        // ensure 0<=theta<360
        if(theta >= 360){theta = 360%static_cast<int>(theta);}
        if(theta < 0){theta = 360+theta;}
        itTransf *= QTransform::fromScale( scale(), scale() );
        itTransf.translate( -dp.x(), -dp.y() );
        setTransform(itTransf);
    }
    else if (event->key() == Qt::Key_Up)
    {
        // for momentum conservation
        velocity += 1;
        // for right now
        setPos(x()+4*qCos(theta*3.14/180), y()+4*qSin(theta*3.14/180));
    }
    else if (event->key() == Qt::Key_Down)
    {
        // for momentum conservation
        velocity -= 1;
        // for right now
        setPos(x()-2*qCos(theta*3.14/180), y()-2*qSin(theta*3.14/180));
    }
    else if (event->key() == Qt::Key_Space)
    {
        // create a bullet
        Bullet *bullet = new Bullet(theta);
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
    }
}
