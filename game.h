#ifndef GAME_H
#define GAME_H
#include "board.h"
class Game {
protected:
    Board board;
    bool isWhiteTurn;
public:
    Game();
    void start();
    void switchTurn();
};
#endif