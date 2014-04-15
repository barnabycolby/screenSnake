#include "model/FoodSquare.h"

FoodSquare::FoodSquare(int x, int y)
: Square(x, y)
{}

const SquareType FoodSquare::getType() const {
	return FOOD;
}
