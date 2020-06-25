#ifndef PICTURE_H
#define PICTURE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class picture: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    picture();
};

#endif // PICTURE_H
