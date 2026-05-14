#include "board.h"
#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

#include <iostream>
#include<cmath>
#include<stdexcept>
using namespace std;

Board::Board()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++) 
        {
            board[i][j] = '.';
        }
    }

    board[0][0] = 'r';
    board[0][7] = 'r';
    board[0][1] = 'n';
    board[0][6] = 'n';
    board[0][2] = 'b';
    board[0][5] = 'b';
    board[0][3] = 'q';
    board[0][4] = 'k';

    for (int i = 0; i < 8; i++) 
    {
        board[1][i] = 'p';
    }

    board[7][0] = 'R';
    board[7][7] = 'R';
    board[7][1] = 'N';
    board[7][6] = 'N';
    board[7][2] = 'B';
    board[7][5] = 'B';
    board[7][3] = 'Q';
    board[7][4] = 'K';

    for (int i = 0; i < 8; i++)
    {
        board[6][i] = 'P';
    }
}

void Board::display()
{
    cout << "  0 1 2 3 4 5 6 7\n";

    for (int i = 0; i < 8; i++) 
    {
        cout << i << " ";
        for (int j = 0; j < 8; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void Board::movePiece(int sx, int sy, int ex, int ey, bool isWhiteTurn)
{
    if (sx == ex && sy == ey)
    {
        throw logic_error("The source and destination cant be same");
    }

    if (sx < 0 || sx >= 8 || sy < 0 || sy >= 8 || ex < 0 || ex >= 8 || ey < 0 || ey >= 8)
    {
        throw out_of_range("The given coordinates are outside the board");
    }

    char piece = board[sx][sy];
  
    if (piece == '.')
    {
        throw runtime_error("There is no piece at selected position");
    }

    if (isWhiteTurn && piece >= 'a' && piece <= 'z')
    {
        throw runtime_error("White cannot move blacks piece");
    }

    if (!isWhiteTurn && piece >= 'A' && piece <= 'Z')
    {
        throw runtime_error("Black cannot move whites piece!");
    }

    char destination = board[ex][ey];

    if ((piece >= 'A' && piece <= 'Z' && destination >= 'A' && destination <= 'Z') || (piece >= 'a' && piece <= 'z' && destination >= 'a' && destination <= 'z'))
    {
        throw logic_error("You cannot capture your own piece");
    }

    if (piece == 'P')
    {
        if (ex == sx - 1 && ey == sy && board[ex][ey] == '.')
        {
        }

        else if (sx == 6 && ex == 4 && ey == sy && board[5][sy] == '.' && board[4][sy] == '.')
        {
        }

        else if (ex == sx - 1 && abs(ey - sy) == 1 && (board[ex][ey] >= 'a' && board[ex][ey] <= 'z'))
        {
        }

        else
        {
            throw invalid_argument("Invalid pawn move");
        }
    }
    if (piece == 'p')
    {

        if (ex == sx + 1 && ey == sy && board[ex][ey] == '.')
        {
        }

        else if (sx == 1 && ex == 3 && ey == sy && board[2][sy] == '.' && board[3][sy] == '.')
        {
        }

        else if (ex == sx + 1 && abs(ey - sy) == 1 && (board[ex][ey] >= 'A' && board[ex][ey] <= 'Z'))
        {
        }

        else
        {
            throw invalid_argument("Invalid pawn move");
        }
    }

    if (piece == 'R' || piece == 'r')
    {
        if (!(sx == ex || sy == ey))
        {
            throw invalid_argument("Invalid rook move");
        }

        if (sx == ex)
        {
            int step = (ey > sy) ? 1 : -1;

            for (int y = sy + step; y != ey; y += step)
            {
                if (board[sx][y] != '.')
                {
                    throw invalid_argument("Invalid rook move");
                }
            }
        }

        if (sy == ey)
        {
            int step = (ex > sx) ? 1 : -1;

            for (int x = sx + step; x != ex; x += step)
            {
                if (board[x][sy] != '.')
                {
                    throw invalid_argument("Invalid rook move");
                }
            }
        }
    }

    if (piece == 'B' || piece == 'b')
    {
        if (abs(ex - sx) != abs(ey - sy))
        {
            throw invalid_argument("Invalid bishop move");
        }

        int stepx = (ex > sx) ? 1 : -1;
        int stepy = (ey > sy) ? 1 : -1;

        int x = sx + stepx;
        int y = sy + stepy;

        while (x != ex && y != ey)
        {
            if (board[x][y] != '.')
            {
                throw invalid_argument("Invalid bishop move");
            }

            x += stepx;
            y += stepy;
        }
    }

    if (piece == 'Q' || piece == 'q')
    {
        if (sx == ex || sy == ey)
        {
            if (sx == ex)
            {
                int step = (ey > sy) ? 1 : -1;

                for (int y = sy + step; y != ey; y += step)
                {
                    if (board[sx][y] != '.')
                    {
                        throw invalid_argument("Invalid queen move");
                    }
                }
            }

            if (sy == ey)
            {
                int step = (ex > sx) ? 1 : -1;

                for (int x = sx + step; x != ex; x += step)
                {
                    if (board[x][sy] != '.')
                    {
                        throw invalid_argument("Invalid queen move");
                    }
                }
            }
        }

        else if (abs(ex - sx) == abs(ey - sy))
        {
            int stepx = (ex > sx) ? 1 : -1;
            int stepy = (ey > sy) ? 1 : -1;

            int x = sx + stepx;
            int y = sy + stepy;

            while (x != ex && y != ey)
            {
                if (board[x][y] != '.')
                {
                    throw invalid_argument("Invalid queen move!");
                }

                x += stepx;
                y += stepy;
            }
        }

        else
        {
            throw invalid_argument("Invalid queen move!");
        }
    }

    if (piece == 'N' || piece == 'n')
    {
        int dx = abs(ex - sx);
        int dy = abs(ey - sy);

        if (!((dx == 2 && dy == 1) ||
            (dx == 1 && dy == 2)))
        {
            throw invalid_argument("Invalid knight move!");
        }
    }

    if (piece == 'K' || piece == 'k')
    {
        if (abs(ex - sx) > 1 || abs(ey - sy) > 1)
        {
            throw invalid_argument("Invalid King move!");
        }
    }

    if (board[ex][ey] == 'K' || board[ex][ey] == 'k')
    {
        throw runtime_error("King cannot be captured!");
    }

    board[ex][ey] = board[sx][sy];
    board[sx][sy] = '.';
}
