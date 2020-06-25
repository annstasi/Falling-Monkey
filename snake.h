#ifndef SNAKE_H
#define SNAKE_H

#include <QGraphicsPixmapItem>

class snake: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    snake();
public slots:
    void move_snake();
};

#endif // SNAKE_H
