#ifndef PLENTY_H
#define PLENTY_H

#include <QGraphicsPixmapItem>
#include <QObject>

//Картинка со связкой бананов
class Plenty: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Plenty();
};

#endif // PLENTY_H
