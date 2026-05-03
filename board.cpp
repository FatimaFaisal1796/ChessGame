#include <iostream>
#include "broad.h"
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
bool Board::movePiece(int sx, int sy, int ex, int ey)
{
    if (sx < 0 || sx >= 8 || sy < 0 || sy >= 8 ||
        ex < 0 || ex >= 8 || ey < 0 || ey >= 8) {
        return false;
    }
    if (board[sx][sy] == '.') 
    {
        return false;
    }

    // move piece
    board[ex][ey] = board[sx][sy];
    board[sx][sy] = '.';

    return true;
}