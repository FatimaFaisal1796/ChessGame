#include <iostream>
#include<cmath>
#include "board.h"
#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
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

    for (int i = 0; i < 8; i++) {
        cout << i << " ";
        for (int j = 0; j < 8; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool Board::movePiece(int sx, int sy, int ex, int ey, bool isWhiteTurn)
{
    if (sx < 0 || sx >= 8 || sy < 0 || sy >= 8 ||
        ex < 0 || ex >= 8 || ey < 0 || ey >= 8) {
        return false;
    }

    char piece = board[sx][sy];
  
    if (piece == '.')
    {
        return false;
    }

    if (isWhiteTurn && piece >= 'a' && piece <= 'z')
    {
        return false;
    }

    if (!isWhiteTurn && piece >= 'A' && piece <= 'Z')
    {
        return false;
    }

    char destination = board[ex][ey];

    if ((piece >= 'A' && piece <= 'Z' &&
        destination >= 'A' && destination <= 'Z') ||

        (piece >= 'a' && piece <= 'z' &&
            destination >= 'a' && destination <= 'z'))
    {
        return false;
    }

    if (piece == 'P')
    {
        if (ex == sx - 1 && ey == sy && board[ex][ey] == '.')
        {
        }

        else if (sx == 6 && ex == 4 && ey == sy &&
            board[5][sy] == '.' &&
            board[4][sy] == '.')
        {
        }

        else if (ex == sx - 1 && abs(ey - sy) == 1 && (board[ex][ey] >= 'a' && board[ex][ey] <= 'z'))
        {
        }

        else
        {
            return false;
        }
    }
    if (piece == 'p')
    {

        if (ex == sx + 1 && ey == sy && board[ex][ey] == '.')
        {
        }

        else if (sx == 1 && ex == 3 && ey == sy &&
            board[2][sy] == '.' &&
            board[3][sy] == '.')
        {
        }

        else if (ex == sx + 1 && abs(ey - sy) == 1 && (board[ex][ey] >= 'A' && board[ex][ey] <= 'Z'))
        {
        }

        else
        {
            return false;
        }
    }

    if (piece == 'R' || piece == 'r')
    {
        if (!(sx == ex || sy == ey))
        {
            return false;
        }

        if (sx == ex)
        {
            int step = (ey > sy) ? 1 : -1;

            for (int y = sy + step; y != ey; y += step)
            {
                if (board[sx][y] != '.')
                {
                    return false;
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
                    return false;
                }
            }
        }
    }

    if (piece == 'B' || piece == 'b')
    {
        if (abs(ex - sx) != abs(ey - sy))
        {
            return false;
        }

        int stepx = (ex > sx) ? 1 : -1;
        int stepy = (ey > sy) ? 1 : -1;

        int x = sx + stepx;
        int y = sy + stepy;

        while (x != ex && y != ey)
        {
            if (board[x][y] != '.')
            {
                return false;
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
                        return false;
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
                        return false;
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
                    return false;
                }

                x += stepx;
                y += stepy;
            }
        }

        else
        {
            return false;
        }
    }

    if (piece == 'N' || piece == 'n')
    {
        int dx = abs(ex - sx);
        int dy = abs(ey - sy);

        if (!((dx == 2 && dy == 1) ||
            (dx == 1 && dy == 2)))
        {
            return false;
        }
    }

    if (piece == 'K' || piece == 'k')
    {
        if (abs(ex - sx) > 1 || abs(ey - sy) > 1)
        {
            return false;
        }
    }

    board[ex][ey] = board[sx][sy];
    board[sx][sy] = '.';

    return true;
}
