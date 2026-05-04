#ifndef KING_H
#define KING_H	
#include "Piece.h"

class King : public Piece
{	
	public:
		King(char c);
		bool isValidMove(int x1, int y1, int x2, int y2);
		char getSymbol();
};

#endif 
