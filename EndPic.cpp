#include "Game.h"
#include "EndPic.h"
#include <QGraphicsScene>


EndPic::EndPic(): QObject(), QGraphicsPixmapItem() {

    setPixmap(QPixmap(":/images/EndPic.png"));
}
