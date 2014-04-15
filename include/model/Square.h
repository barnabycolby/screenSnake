#ifndef SQUARE_H
#define SQUARE_H

enum SquareType { EMPTY, SNAKE, FOOD };

class Square {
public:
	Square(int currentx, int currenty);
	const virtual SquareType getType() const;
	int getX();
	int getY();
	void setX(int newX);
	void setY(int newY);

private:
	int x;
	int y;
};

#endif
