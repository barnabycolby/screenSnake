#ifndef FOOD_SQUARE_H
#define FOOD_SQUARE_H

#include "model/Square.h"

class FoodSquare : public Square {
public:
	FoodSquare(int x, int y);
	const SquareType getType() const;
};

#endif
