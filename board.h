#ifndef BOARD_H
#define BOARD_H

class Board
{
protected:
    char board[8][8];

public:
    Board();
    void display();
    bool movePiece(int sx, int sy, int ex, int ey);
    bool isPathClear(int sx, int sy, int ex, int ey);
};
#endif
