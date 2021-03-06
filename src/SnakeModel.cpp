#include "SnakeModel.h"

#include "model/SnakeSquare.h"
#include "model/FoodSquare.h"

#include <stdlib.h>
#include <time.h>

SnakeModel::SnakeModel()
: gridWidth(30), gridHeight(15), direction(NORTH)
{
	// Seed the random number used for generating the foods position
	srand(time(NULL));

	// Generate the snake and food
	this->generateSnake();
	this->food = new FoodSquare(0, 0);
	this->moveFood();

	// Instantiate the direction mutex object
	this->directionMutex = new QMutex();
}

int SnakeModel::getGridWidth() {
	return this->gridWidth;
}

int SnakeModel::getGridHeight() {
	return this->gridHeight;
}

void SnakeModel::generateSnake() {
	list<SnakeSquare*> *newSnake = new list<SnakeSquare*>();

	int centerx = this->getGridWidth() / 2;
	int centery = this->getGridHeight() / 2;
	newSnake->push_front(new SnakeSquare(centerx, centery));

	this->snake = newSnake;
}

vector<Square*> *SnakeModel::getOccupiedSquares() {
	vector<Square*> *occupiedSquares = new vector<Square*>();

	// Add snake squares
	for (SnakeSquare *square : *(this->snake)) {
		occupiedSquares->push_back(square);
	}

	// Add food square
	occupiedSquares->push_back(this->food);

	return occupiedSquares;
}

void SnakeModel::moveFood() {
	// Generate the new x and y
	int randomX, randomY;

	// Keep generating new coordinates until we find an empty square
	do {
		// Generate random coordinates
		randomX = rand() % this->getGridWidth();
		randomY = rand() % this->getGridHeight();
	}
	while (coordinatesContainSnake(randomX, randomY));

	// Set the foods new position
	this->food->setX(randomX);
	this->food->setY(randomY);
}

bool SnakeModel::update() {
	// Set the direction
	this->directionMutex->lock();
	this->direction = this->directionToSet;
	this->directionMutex->unlock();

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

	// If the new coordinates are invalid then we should exit the game
	if (newX < 0 || newX > this->getGridWidth()-1 || newY < 0 || newY > this->getGridHeight()-1
		|| coordinatesContainSnake(newX, newY)) {
		return false;
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

	return true;
}

void SnakeModel::setDirection(SnakeDirection newDirection) {
	this->directionMutex->lock();
	this->directionToSet = newDirection;
	this->directionMutex->unlock();
}

SnakeDirection SnakeModel::getDirection() {
	return this->direction;
}

bool SnakeModel::coordinatesContainSnake(int x, int y) {
	bool coordinatesContainSnake = false;
	for (SnakeSquare *snakeSquare : *(this->snake)) {
		if (snakeSquare->getX() == x && snakeSquare->getY() == y) {
			coordinatesContainSnake = true;
			break;
		}
	}

	return coordinatesContainSnake;
}

SnakeModel::~SnakeModel() {
	delete this->food;

	for (SnakeSquare *snakeSquare : *(this->snake)) {
		delete snakeSquare;
	}
	delete this->snake;

	delete this->directionMutex;
}
