#include "SnakeController.h"

#include <QtGui/QKeyEvent>

#include <iostream>

SnakeController::SnakeController(SnakeModel *snakeModel)
: QWidget(0), snakeModel(snakeModel)
{
	// Grab the keyboard to make sure that the controller gets all of the keyboard input
	this->grabKeyboard();
}

void SnakeController::keyPressEvent(QKeyEvent *event) {
	// Get the current direction of the snake to prevent reversing it's direction
	SnakeDirection currentDirection = this->snakeModel->getDirection();

	switch (event->key()) {
	case Qt::Key_Left:
		if (currentDirection != EAST) {
			this->snakeModel->setDirection(WEST);
		}
		break;
	case Qt::Key_Up:
		if (currentDirection != SOUTH) {
			this->snakeModel->setDirection(NORTH);
		}
		break;
	case Qt::Key_Right:
		if (currentDirection != WEST) {
			this->snakeModel->setDirection(EAST);
		}
		break;
	case Qt::Key_Down:
		if (currentDirection != NORTH) {
			this->snakeModel->setDirection(SOUTH);
		}
		break;

	// If we do not handle the key event, it should be passed to the super method
	default:
		QWidget::keyPressEvent(event);
		break;
	}
}
