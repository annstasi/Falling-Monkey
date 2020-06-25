#include "Counter.h"
#include <QFont>

Counter::Counter(QGraphicsItem *parent): QGraphicsTextItem(parent) {
    counter = 0;
    //Отображаем счётчик бананов
    setPlainText(QString::number(counter));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("arial",18));
}

void Counter::increaseCounter(){
    counter++;
        setPlainText(QString::number(counter));
}
