#include "Game.h"
#include "Plenty.h"
#include <QGraphicsScene>


Plenty::Plenty(): QObject(), QGraphicsPixmapItem() {
    //Картинка со связкой бананов
    setPixmap(QPixmap(":/images/plenty.png"));
}
