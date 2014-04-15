#include "SnakeModel.h"

#include "model/SnakeSquare.h"
#include "model/FoodSquare.h"

SnakeModel::SnakeModel()
: gridWidth(20), gridHeight(10)
{}

int SnakeModel::getGridWidth() {
	return this->gridWidth;
}

int SnakeModel::getGridHeight() {
	return this->gridHeight;
}

vector<vector<Square*>*> *SnakeModel::getGrid() {
	// Initialise the grid with empty
	vector<vector<Square*>*>* grid = new vector<vector<Square*>*>();
	for (int i = 0; i < this->getGridHeight(); i++) {
		vector<Square*>* row = new vector<Square*>();
		for (int j = 0; j < this->getGridWidth(); j++) {
			row->push_back(new Square());
		}
		grid->push_back(row);
	}

	// Add snake squares
	for (int i = 0; i < 5; i++) {
		delete grid->at(7)->at(8+i);
		grid->at(7)->at(8+i) = new SnakeSquare();
	}

	// Add food square
	delete grid->at(2)->at(15);
	grid->at(2)->at(15) = new FoodSquare();
	
	// Return
	return grid;
}
