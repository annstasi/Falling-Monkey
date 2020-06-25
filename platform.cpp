#include "platform.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include <stdlib.h>

platform::platform(): QObject(), QGraphicsPixmapItem() {
    //Устанавливаем позицию
    int random_number = rand() % 600; //делим, чтобы платформы не вышли за поле
    setPos(random_number, 800);

    //Рисуем лиану
    setPixmap(QPixmap(":/images/platform.png"));
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));

    timer->start(17);
}

void platform::move() {
     //Двигаем лиану
    setPos(x(),y()-5);
    //Удаляем её при выходе за границы
  if (pos().y()  < -230) {
       scene()->removeItem(this);
       delete this;
    }
}
