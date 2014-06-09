#include "SnakeModel.h"

#include "model/SnakeSquare.h"
#include "model/FoodSquare.h"

#include <stdlib.h>
#include <time.h>

#include <iostream>

SnakeModel::SnakeModel()
: gridWidth(30), gridHeight(15), direction(NORTH)
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
	for (SnakeSquare *square : *(this->snake)) {
		grid->at(square->getY())->at(square->getX()) = SNAKE;
	}

	// Add food square
	grid->at(this->food->getY())->at(this->food->getX()) = FOOD;
	
	// Return
	return grid;
}

void SnakeModel::generateSnake() {
	list<SnakeSquare*> *newSnake = new list<SnakeSquare*>();

	int centerx = this->getGridWidth() / 2;
	int centery = this->getGridHeight() / 2;
	newSnake->push_front(new SnakeSquare(centerx, centery));

	this->snake = newSnake;
}

void SnakeModel::moveFood() {
	// Generate the new x and y
	int randomX, randomY;
	while (true) {
		// Generate random coordinates
		randomX = rand() % this->getGridWidth();
		randomY = rand() % this->getGridHeight();

		// Check whether the coordinates are empty or not
		for (SnakeSquare *snakeSquare : *(this->snake)) {
			if (snakeSquare->getX() == randomX || snakeSquare->getY() == randomY) {
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

void SnakeModel::update() {
	// Calculate the position of the next square
	SnakeSquare *snakeHead = this->snake->front();
	int newX = snakeHead->getX();
	int newY = snakeHead->getY();
	switch (this->direction) {
	case NORTH:
		newY -= 1;
		break;
	case EAST:
		newX += 1;
		break;
	case SOUTH:
		newY += 1;
		break;
	case WEST:
		newX -= 1;
		break;
	}

	// If the next square is a food square
	if (newX == this->food->getX() && newY == this->food->getY()) {
		// Add a new square to the front of the list
		SnakeSquare *newSquare = new SnakeSquare(newX, newY);
		this->snake->push_front(newSquare);

		// Move the food
		this->moveFood();
	}

	else {
		// Move the last square in the list to the front
		SnakeSquare *squareToMove = this->snake->back();
		this->snake->pop_back();
		this->snake->push_front(squareToMove);
		
		// Set the new coordinates of the head
		squareToMove->setX(newX);
		squareToMove->setY(newY);
	}
}
