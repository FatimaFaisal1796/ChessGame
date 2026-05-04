#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"

class Knight : public Piece 
{
public:
    Knight(char c);

    bool isValidMove(int x1, int y1, int x2, int y2);
    char getSymbol();
};

#endif 

