#include "model/SnakeSquare.h"

SnakeSquare::SnakeSquare(int x, int y)
: Square(x, y)
{}

const SquareType SnakeSquare::getType() const {
	return SNAKE;
}
