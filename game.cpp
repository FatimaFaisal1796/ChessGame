#include "game.h"
#include <iostream>
using namespace std;
Game::Game()
{
    isWhiteTurn = true;
}
void Game::start() 
{
    while (true)
    {
        board.display();

        if (isWhiteTurn)
        {
           cout << "White's turn\n";
        }
        else
        {
           cout << "Black's turn\n";
        }

        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;

        if (board.movePiece(sx, sy, ex, ey)) {
            switchTurn();
        }
        else {
           cout << "Invalid move!\n";
        }
    }
}

void Game::switchTurn() {
    isWhiteTurn = !isWhiteTurn;
}