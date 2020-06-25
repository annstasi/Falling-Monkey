#ifndef ENDPIC_H
#define ENDPIC_H

#include <QGraphicsPixmapItem>
#include <QObject>

//Картинка завершения игры
class EndPic: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    EndPic();
};

#endif // ENDPIC_H
