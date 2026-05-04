#include "Bishop.h"

Bishop::Bishop(char c) : Piece(c) {}

bool Bishop::isValidMove(int x1, int y1, int x2, int y2) 
{
    return abs(x2 - x1) == abs(y2 - y1);
}

char Bishop::getSymbol() 
{
    return (color == 'W') ? 'B' : 'b';
}