#ifndef SNAKE_MODEL_H
#define SNAKE_MODEL_H

#include "model/Square.h"

#include <vector>

using namespace std;

class SnakeModel {
public:
	SnakeModel();

private:
	int gridWidth;
	int gridHeight;

//	vector<Square> *squares

public:
	int getGridWidth();
	int getGridHeight();
	vector<vector<SquareType>*> *getGrid();
};

#endif
