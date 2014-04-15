#ifndef SNAKE_SQUARE_H
#define SNAKE_SQUARE_H

#include "model/Square.h"

class SnakeSquare : public Square {
public:
	SnakeSquare(int x, int y);
	const SquareType getType() const;
};

#endif
