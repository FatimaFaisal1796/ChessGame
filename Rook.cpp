#include "Rook.h"

Rook::Rook(char c) : Piece(c) {}

bool Rook::isValidMove(int x1, int y1, int x2, int y2) 
{
    return (x1 == x2 || y1 == y2);
}

char Rook::getSymbol() 
{
    return (color == 'W') ? 'R' : 'r';
}