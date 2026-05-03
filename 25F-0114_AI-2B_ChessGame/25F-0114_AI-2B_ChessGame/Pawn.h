#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece 
{
public:
    Pawn(char c);

    bool isValidMove(int x1, int y1, int x2, int y2);
    char getSymbol();
};

#endif