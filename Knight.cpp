#include "Knight.h"

Knight::Knight(char c) : Piece(c) {}

bool Knight::isValidMove(int x1, int y1, int x2, int y2) 
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}

char Knight::getSymbol() 
{
    return (color == 'W') ? 'N' : 'n';
}