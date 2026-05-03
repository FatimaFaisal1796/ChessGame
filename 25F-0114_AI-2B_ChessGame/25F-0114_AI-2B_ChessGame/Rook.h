#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"

class Rook : public Piece 
{
public:
    Rook(char c);

    bool isValidMove(int x1, int y1, int x2, int y2);
    char getSymbol();
};

#endif
