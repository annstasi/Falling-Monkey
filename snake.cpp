#include "snake.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include <stdlib.h>

snake::snake(): QObject(), QGraphicsPixmapItem() {
    //Устанавливаем позицию
    int generate_snake = rand() % 600; //делим, чтобы змеи не вышли за поле
    setPos(generate_snake, 800);

    //Рисуем банан
    setPixmap(QPixmap(":/images/snake.png"));
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(move_snake()));

    timer->start(30);
}

void snake::move_snake() {
     //Двигаем змею
    setPos(x(),y()-6);
    //Удаляем змею при выходе за границы
  if (pos().y()  < -230) {
       scene()->removeItem(this);
       delete this;
    }
}
