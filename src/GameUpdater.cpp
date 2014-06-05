#include "GameUpdater.h"

GameUpdater::GameUpdater(QApplication *qApplication, SnakeModel *snakeModel, SnakeView *snakeView)
: QThread(qApplication), snakeModel(snakeModel), snakeView(snakeView)
{}

void GameUpdater::run() {
	// Initialise a timer
	this->startTimer(1000);

	// Start an event loop for this thread so that it can use a timer
	this->exec();
}

void GameUpdater::timerEvent(QTimerEvent *event) {
	// Update the snake model
	this->snakeModel->update();

	// Update the view to show the udpated model
	this->snakeView->repaint();
}
