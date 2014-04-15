#ifndef SQUARE_H
#define SQUARE_H

enum SquareType { EMPTY, SNAKE, FOOD };

class Square {
public:
	const virtual SquareType getType() const;
};

#endif
