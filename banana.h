#ifndef BANANA_H
#define BANANA_H

#include <QGraphicsPixmapItem>

class banana: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    banana();
public slots:
    void move_banana();
};

#endif // BANANA_H
