#include "Player.h"
#include "Counter.h"
#include "platform.h"
#include "banana.h"
#include "snake.h"
#include "Game.h"
#include "Score.h"
#include "Health.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>

extern Game *game;
void Player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left) {
        if (pos().x() > 0)
        setPos(x()-9,y());
    }
    if (event->key() == Qt::Key_Right) {
        if (pos().x()+ 125 < 700)
        setPos(x()+9,y());
    }
}

void Player::spawn() {
    //Генерируем лиану
platform *platform = new class platform();
scene()->addItem(platform);
}

void Player::banana_spawn() {
    //Генерируем банан
banana *banana = new class banana();
scene()->addItem(banana);
}

void Player::snake_spawn() {
    //Генерируем змею
snake *snake = new class snake();
scene()->addItem(snake);
}

Player::Player(): QObject(), QGraphicsPixmapItem() {

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(move_player()));

    timer->start(10);
}
void Player::move_player() {
    //Осуществляем падение обезьянки
    setPos(x(),y()+1);
    //Увеличиваем пройденные метры
    game->score->increase();
    //Если обезьяна упала или здоровье 0 - конец игры
    if ((pos().y() > 800) || (game->health->getHealth() == 0)) {
        game->GameOver();
        //Удаляем обезьянку с поля
        delete(this);
    }
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if(typeid(*(colliding_items[i])) == typeid (platform)) {
            //При столкновении с платформой поднимаем игрока вверх
            setPos(x(),y()-2.5);
        }
        else if(typeid(*(colliding_items[i])) == typeid (banana)) {
            //При столкновении с бананом, увеличиваем счётчик и удаляем его с поля
            scene()->removeItem(colliding_items[i]);
            game->counter->increaseCounter();
            delete colliding_items[i];
        }
        else if(typeid (*(colliding_items[i])) == typeid (snake)) {
            //При столкновении со змеёй, уменьшаем здоровье и удаляем её с поля
            scene()->removeItem(colliding_items[i]);
            game->health->decreaseHealth();
            delete colliding_items[i];
        }
    }
}

