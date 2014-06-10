#include "GameUpdater.h"

GameUpdater::GameUpdater(QApplication *qApplication, SnakeModel *snakeModel, SnakeView *snakeView)
: QThread(qApplication), qApplication(qApplication), snakeModel(snakeModel), snakeView(snakeView)
{}

void GameUpdater::run() {
	// Initialise a timer
	this->startTimer(200);

	// Start an event loop for this thread so that it can use a timer
	this->exec();
}

void GameUpdater::timerEvent(QTimerEvent *event) {
	// Update the snake model
	if (!this->snakeModel->update()) {
		this->qApplication->quit();
		this->quit();
	}

	// Update the view to show the udpated model
	this->snakeView->update();
}
