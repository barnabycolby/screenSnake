#include "model/Square.h"

Square::Square(int currentx, int currenty)
: x(currentx), y(currenty)
{}

const SquareType Square::getType() const {
	return EMPTY;
}

int Square::getX() {
	return this->x;
}

int Square::getY() {
	return this->y;
}

void Square::setX(int newX) {
	this->x = newX;
}

void Square::setY(int newY) {
	this->y = newY;
}
