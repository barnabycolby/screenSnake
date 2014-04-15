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

public:
	int getGridWidth();
	int getGridHeight();
	vector<vector<Square*>*> *getGrid();
};

#endif
