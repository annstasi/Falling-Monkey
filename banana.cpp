#include "banana.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include <stdlib.h>

banana::banana(): QObject(), QGraphicsPixmapItem() {
    //Устанавливаем позицию
    int generate_number = rand() % 600; //делим, чтобы банааны не вышли за поле
    setPos(generate_number, 800);

    //Рисуем банан
    setPixmap(QPixmap(":/images/banana.png"));
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(move_banana()));

    timer->start(30);
}

void banana::move_banana() {
     //Двигаем банан
    setPos(x(),y()-5);
    //Удаляем его при выходе за границы
  if (pos().y()  < -230) {
       scene()->removeItem(this);
       delete this;
    }
}
