#include "King.h"

King::King(char c) : Piece(c) {}

bool King::isValidMove(int x1, int y1, int x2, int y2) 
{
    return abs(x2 - x1) <= 1 && abs(y2 - y1) <= 1;
}

char King::getSymbol() 
{
    return (color == 'W') ? 'K' : 'k';
}