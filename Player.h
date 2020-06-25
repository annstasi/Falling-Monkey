#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Player: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent *event);
    Player();

public slots:
    void spawn();
    void banana_spawn();
    void move_player();
    void snake_spawn();
};

#endif // PLAYER_H
