#include "mainship.h"

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

void mainship::updatePos()
{
    setPos(x()+velocity*qCos(theta), y()+velocity*qSin(theta));
}*/

void mainship::keyPressEvent(QKeyEvent *event)
{
    //std::cout<<"theta"<<theta<<"\n";
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
        velocity += 1;
        setPos(x()+4*qCos(theta*3.14/180), y()+4*qSin(theta*3.14/180));
    }
    else if (event->key() == Qt::Key_Down)
    {
        velocity -= 1;
        setPos(x()-2*qCos(theta*3.14/180), y()-2*qSin(theta*3.14/180));
    }
    else if (event->key() == Qt::Key_Space)
    {
        // create a bullet
        Bullet * bullet = new Bullet(theta);
        bullet->setPos(x(),y());
        std::cout<<"theta"<<theta<<"\n";
        //bullet->angle = theta;
        //bullet->setAngle2(theta);
        scene()->addItem(bullet);
    }
}
