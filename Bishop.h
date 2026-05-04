#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"

class Bishop : public Piece 
{
	public:
		Bishop(char c);
		bool isValidMove(int x1, int y1, int x2, int y2);
		char getSymbol();
};

#endif
