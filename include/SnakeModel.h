#ifndef SNAKE_MODEL_H
#define SNAKE_MODEL_H

#include "model/Square.h"
#include "model/SnakeSquare.h"
#include "model/FoodSquare.h"

#include <vector>

using namespace std;

class SnakeModel {
public:
	SnakeModel();

private:
	int gridWidth;
	int gridHeight;

	vector<SnakeSquare> *snake;
	FoodSquare *food;

public:
	int getGridWidth();
	int getGridHeight();
	vector<vector<SquareType>*> *getGrid();

private:
	void generateSnake();
	void moveFood();
};

#endif
