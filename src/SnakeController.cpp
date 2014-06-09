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
	switch (event->key()) {
	case Qt::Key_Left:
		this->snakeModel->setDirection(WEST);
		break;
	case Qt::Key_Up:
		this->snakeModel->setDirection(NORTH);
		break;
	case Qt::Key_Right:
		this->snakeModel->setDirection(EAST);
		break;
	case Qt::Key_Down:
		this->snakeModel->setDirection(SOUTH);
		break;

	// If we do not handle the key event, it should be passed to the super method
	default:
		QWidget::keyPressEvent(event);
		break;
	}
}
