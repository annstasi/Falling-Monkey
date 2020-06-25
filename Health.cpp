#include "Health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent) {
    health = 100;
    //Отображаем здоровье игрока
    setPlainText(QString("здоровье ")+QString::number(health)+QString(" %"));
    setDefaultTextColor(Qt::white);
    setFont(QFont("arial",16));
}

void Health::decreaseHealth(){
    health=health-25;
        setPlainText(QString("здоровье ")+QString::number(health)+QString(" %"));
}
int Health::getHealth(){
    return health;
}
