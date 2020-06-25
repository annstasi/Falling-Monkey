#include "picture.h"
#include <QGraphicsScene>
#include <QList>
picture::picture(): QObject(), QGraphicsPixmapItem() {
    setPixmap(QPixmap(":/images/banana.png"));
    setPos(8,45);
}
