#ifndef SNAKE_MODEL_H
#define SNAKE_MODEL_H

#include "model/Square.h"
#include "model/SnakeSquare.h"
#include "model/FoodSquare.h"
#include "SnakeDirection.h"

#include <vector>
#include <list>

using namespace std;

class SnakeModel {
public:
	SnakeModel();

private:
	int gridWidth;
	int gridHeight;

	list<SnakeSquare*> *snake;
	FoodSquare *food;

	SnakeDirection direction;
	SnakeDirection directionToSet;

public:
	int getGridWidth();
	int getGridHeight();
	vector<vector<SquareType>*> *getGrid();
	bool update();
	void setDirection(SnakeDirection newDirection);
	SnakeDirection getDirection();

private:
	void generateSnake();
	void moveFood();
	bool coordinatesContainSnake(int x, int y);
};

#endif
