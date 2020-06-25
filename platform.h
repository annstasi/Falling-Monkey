#ifndef PLATFORM_H
#define PLATFORM_H

#include <QGraphicsPixmapItem>
#include <QObject>

class platform: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    platform();
public slots:
    void move();
};

#endif // PLATFORM_H
