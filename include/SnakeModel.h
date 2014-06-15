#ifndef SNAKE_MODEL_H
#define SNAKE_MODEL_H

#include "model/Square.h"
#include "model/SnakeSquare.h"
#include "model/FoodSquare.h"
#include "SnakeDirection.h"

#include <vector>
#include <list>

#include <QtCore/QMutex>

using namespace std;

class SnakeModel {
public:
	SnakeModel();
	~SnakeModel();

private:
	int gridWidth;
	int gridHeight;

	list<SnakeSquare*> *snake;
	FoodSquare *food;

	QMutex *directionMutex;
	SnakeDirection direction;
	SnakeDirection directionToSet;

public:
	int getGridWidth();
	int getGridHeight();
	vector<Square*> *getOccupiedSquares();
	bool update();
	void setDirection(SnakeDirection newDirection);
	SnakeDirection getDirection();

private:
	void generateSnake();
	void moveFood();
	bool coordinatesContainSnake(int x, int y);
};

#endif
