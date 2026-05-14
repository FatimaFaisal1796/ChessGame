#ifndef BOARD_H
#define BOARD_H

class Board
{
protected:

    char board[8][8];
public:

    Board();
    void display();
    void movePiece(int sx, int sy, int ex, int ey, bool isWhiteTurn);
    bool isKingInCheck(bool isWhite);
    char* getPiece(int x, int y) 
    { 
        return &board[x][y]; 
    }
};
#endif
