#include <QApplication>
#include <QGraphicsScene>
#include <QPolygon>

int main(int argc, char *argv[]){


    QApplication a(argc, argv);

    QGraphicsScene * scene = new QGraphicsScene();

    // Describe a closed triangle
    QPolygonF Triangle;
    Triangle.append(QPointF(-10.,0));
    Triangle.append(QPointF(0.,-10));
    Triangle.append(QPointF(10.,0));
    Triangle.append(QPointF(-10.,0));

    // Add the triangle polygon to the scene
    QGraphicsPolygonItem* pTriangleItem = pScene->addPolygon(Triangle);
    scene->addItem(pTriangleItem);


    return a.exec();
}
