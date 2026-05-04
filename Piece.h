#ifndef PIECE_H
#define PIECE_H 
#include<iostream>
#include<cmath>
using namespace std;    

class Piece 
{
protected:
    char color;

public:
    Piece(char c) 
    { 
        color = c; 
    }

    virtual bool isValidMove(int x1, int y1, int x2, int y2) = 0;
    virtual char getSymbol() = 0;
};
#endif 