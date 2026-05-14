#include "game.h"
#include <iostream>
#include<stdexcept>

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
           cout << "\nWhite's turn\n";
        }
        else
        {
           cout << "\nBlack's turn\n";
        }

        int sx, sy, ex, ey;

        cin >> sx >> sy >> ex >> ey;

        if (cin.fail())
        {
            cin.clear();

            cin.ignore(1000, '\n');

            throw invalid_argument("Please enter integers only");
        }

        try
        {
            board.movePiece(sx, sy, ex, ey, isWhiteTurn);

            switchTurn();
        }
        catch (exception& e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }
}

void Game::switchTurn() 
{
    isWhiteTurn = !isWhiteTurn;
}
