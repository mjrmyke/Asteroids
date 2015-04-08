#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPolygon>
#include <QBrush>
#include <QImage>
#include <QPainter>
#include <QColor>
#include "myship.h"



int main(int argc, char *argv[]){


    QApplication a(argc, argv);

    QGraphicsScene * scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    scene->setBackgroundBrush(QBrush(QImage(":/images/bg.png")));
    Qt::ScrollBarAlwaysOff;

    // create an item to add to the scene
    myship * ship = new myship();
    ship->setTransformOriginPoint(12.5,12.5);
    ship->setRect(0,0,25,25); // change the rect size
    ship->setPen(QPen(Qt::red, 5));
    QPainter::SmoothPixmapTransform;



    ship->setPos(400,300);
    // add the item to the scene
    scene->addItem(ship);

    // make rect focusable
    ship->setFlag(QGraphicsItem::ItemIsFocusable);
    ship->setFocus();



    QGraphicsView * view = new QGraphicsView(scene);


    // show the view
    view->show();
    return a.exec();
}
