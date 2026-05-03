#include "Pawn.h"

Pawn::Pawn(char c) : Piece(c) {}

bool Pawn::isValidMove(int x1, int y1, int x2, int y2)
{
    if (color == 'W')
    {
        return (x2 == x1 - 1 && y1 == y2) ||
            (x1 == 6 && x2 == 4 && y1 == y2); 
    }
    else
    {
        return (x2 == x1 + 1 && y1 == y2) ||
            (x1 == 1 && x2 == 3 && y1 == y2);
    }
}

char Pawn::getSymbol() 
{
    return (color == 'W') ? 'P' : 'p';
}