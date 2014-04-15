#include "SnakeModel.h"

#include "model/SnakeSquare.h"
#include "model/FoodSquare.h"

#include <stdlib.h>
#include <time.h>

SnakeModel::SnakeModel()
: gridWidth(30), gridHeight(15)
{
	// Seed the random number used for generating the foods position
	srand(time(NULL));

	// Generate the snake and food
	this->generateSnake();
	this->food = new FoodSquare(0, 0);
	this->moveFood();
}

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
	for (SnakeSquare square : *(this->snake)) {
		grid->at(square.getY())->at(square.getX()) = SNAKE;
	}

	// Add food square
	grid->at(this->food->getY())->at(this->food->getX()) = FOOD;
	
	// Return
	return grid;
}

void SnakeModel::generateSnake() {
	vector<SnakeSquare> *newSnake = new vector<SnakeSquare>();

	int centerx = this->getGridWidth() / 2;
	int centery = this->getGridHeight() / 2;
	newSnake->push_back(*(new SnakeSquare(centerx, centery)));

	this->snake = newSnake;
}

void SnakeModel::moveFood() {
	// Generate the new x and y
	int randomX, randomY;
	while (true) {
		// Generate random coordinates
		randomX = rand() % (this->getGridWidth() + 1);
		randomY = rand() % (this->getGridHeight() + 1);

		// Check whether the coordinates are empty or not
		for (SnakeSquare snakeSquare : *(this->snake)) {
			if (snakeSquare.getX() == randomX || snakeSquare.getY() == randomY) {
				continue;
			}
		}

		// The square must be valid!
		break;
	}

	// Set the foods new position
	this->food->setX(randomX);
	this->food->setY(randomY);
}
