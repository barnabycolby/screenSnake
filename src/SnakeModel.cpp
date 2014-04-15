#include "SnakeModel.h"

#include "model/SnakeSquare.h"
#include "model/FoodSquare.h"

SnakeModel::SnakeModel()
: gridWidth(30), gridHeight(15)
{}

int SnakeModel::getGridWidth() {
	return this->gridWidth;
}

int SnakeModel::getGridHeight() {
	return this->gridHeight;
}

vector<vector<SquareType>*> *SnakeModel::getGrid() {
	// Initialise the grid with empty
	vector<vector<SquareType>*>* grid = new vector<vector<SquareType>*>();
	for (int i = 0; i < this->getGridHeight(); i++) {
		vector<SquareType>* row = new vector<SquareType>();
		for (int j = 0; j < this->getGridWidth(); j++) {
			row->push_back(EMPTY);
		}
		grid->push_back(row);
	}

	// Add snake squares
	for (int i = 0; i < 5; i++) {
		grid->at(7)->at(8+i) = SNAKE;
	}

	// Add food square
	grid->at(2)->at(15) = FOOD;
	
	// Return
	return grid;
}
