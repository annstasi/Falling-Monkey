#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent) {
    score = 0;
    //Отображаем пройденные "метры"
    setPlainText(QString::number(score)+QString(" m"));
    setDefaultTextColor(Qt::white);
    setFont(QFont("arial",18));
}

void Score::increase(){
    score=score+0.1;
        setPlainText(QString::number(score)+QString(" m"));
}

