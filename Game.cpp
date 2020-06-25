#include "platform.h"
#include "banana.h"
#include "Game.h"
#include "Button.h"
#include "Plenty.h"
#include "EndPic.h"
#include <QTimer>
#include <QBrush>

Game::Game(QWidget *parent){
     scene = new QGraphicsScene();
     scene->setSceneRect(0,0,700,800);
     setBackgroundBrush(QBrush(QImage(":/images/bg.png")));

     setScene(scene);
     //Убираем прокрутку
     setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
     setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
     setFixedSize(700,800);

    //Добавляем счёт
    score = new Score();
    scene->addItem(score);

    //Добавляем здоровье
    health = new Health();
    health->setPos(490,0);
    scene->addItem(health);

    //Добавляем счётчик бананов
    counter = new Counter();
    counter->setPos(6,50);
    scene->addItem(counter);

    //Устанавливаем картинку связки бананов напротив счётчика
    plenty = new Plenty;
    plenty->setPos(50,50);
    scene->addItem(plenty);

    //Добавляем игрока
    player = new Player();
    player->setPixmap(QPixmap(":/images/monkey_armsup.png"));
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //Устанавливаем игрока на сцене
    player->setPos(100,50);
    scene->addItem(player);

    //Генерируем лианы
    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(1800);
    show();

    //Генерируем бананы
    QTimer *timer2 = new QTimer();
    QObject::connect(timer2,SIGNAL(timeout()),player,SLOT(banana_spawn()));
    timer2->start(3600);
    show();

    //Генерируем змей
    QTimer *timer3 = new QTimer();
    QObject::connect(timer3,SIGNAL(timeout()),player,SLOT(snake_spawn()));
    timer3->start(8000);
    show();
}

void Game::GameOver()
{
    //Сообщение о конце игры
    QString messege;
    displayGameOverWindow(messege);
}

void Game::drawEnd(int x, int y, int width, int height, QColor color, double opacity)
{
    QGraphicsRectItem *endgame = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    endgame->setBrush(brush);
    endgame->setOpacity(opacity);
    scene->addItem(endgame);

}

//Конец игры с кнопкой выхода
void Game::displayGameOverWindow(QString)
{
    drawEnd(0,110,700,800,Qt::white,0.70);
    endpic = new EndPic;
    endpic->setPos(55,0);
    scene->addItem(endpic);
    Button *quit = new Button(QString("ВЫХОД"));
    quit->setPos(245,300);
    scene->addItem(quit);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));
}

