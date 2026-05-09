#ifndef GAME_H
#define GAME_H
#include "Board.h"

class Game 
{
protected:
    Board board;
    bool isWhiteTurn;

public:
    Game();
    void start();
    void switchTurn();
};
#endif
