#include "SnakeController.h"

#include <QtGui/QKeyEvent>

SnakeController::SnakeController(QApplication *qApplication, SnakeModel *snakeModel, GameUpdater *gameUpdater)
: QWidget(0), qApplication(qApplication), snakeModel(snakeModel), gameUpdater(gameUpdater)
{
	// Grab the keyboard to make sure that the controller gets all of the keyboard input
	this->grabKeyboard();
}

void SnakeController::keyPressEvent(QKeyEvent *event) {
	// Get the current direction of the snake to prevent reversing it's direction
	SnakeDirection currentDirection = this->snakeModel->getDirection();

	switch (event->key()) {
	// Handle direction keys
	case Qt::Key_Left:
		if (currentDirection != EAST && !this->gameUpdater->isPaused()) {
			this->snakeModel->setDirection(WEST);
		}
		break;
	case Qt::Key_Up:
		if (currentDirection != SOUTH && !this->gameUpdater->isPaused()) {
			this->snakeModel->setDirection(NORTH);
		}
		break;
	case Qt::Key_Right:
		if (currentDirection != WEST && !this->gameUpdater->isPaused()) {
			this->snakeModel->setDirection(EAST);
		}
		break;
	case Qt::Key_Down:
		if (currentDirection != NORTH && !this->gameUpdater->isPaused()) {
			this->snakeModel->setDirection(SOUTH);
		}
		break;

	// We should exit on ESC
	case Qt::Key_Escape:
		this->qApplication->quit();
		return;
		break;

	// Pause the game on the p key
	case Qt::Key_P:
		this->gameUpdater->togglePause();
		break;

	// If we do not handle the key event, it should be passed to the super method
	default:
		QWidget::keyPressEvent(event);
		break;
	}
}
