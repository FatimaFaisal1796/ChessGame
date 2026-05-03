#include "Queen.h" 

Queen::Queen(char c) : Piece(c) {}

bool Queen::isValidMove(int x1, int y1, int x2, int y2) 
{
    return (x1 == x2 || y1 == y2 || abs(x2 - x1) == abs(y2 - y1));
}

char Queen::getSymbol() 
{
    return (color == 'W') ? 'Q' : 'q';
}