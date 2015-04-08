#ifndef myship_h
#define myship_h

#include <QGraphicsItem>


class myship: public QGraphicsRectItem{
public:
    void keyPressEvent(QKeyEvent * event);
    qreal angle(qreal&);
};

#endif
