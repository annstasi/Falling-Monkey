#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Counter.h"
#include "Plenty.h"
#include "Health.h"
#include "EndPic.h"

class Game: public QGraphicsView {
public:
    Game(QWidget *parent = 0);
    QGraphicsScene *scene;
    Player *player;
    Counter *counter;
    Health *health;
    Score *score;
    Plenty *plenty;
    EndPic *endpic;
    void GameOver();
    void displayGameOverWindow(QString);
    void drawEnd(int x, int y, int width, int height, QColor color, double opacity);
};

#endif // GAME_H
