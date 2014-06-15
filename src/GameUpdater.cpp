#include "GameUpdater.h"

GameUpdater::GameUpdater(QApplication *qApplication, SnakeModel *snakeModel, SnakeView *snakeView)
: qApplication(qApplication), snakeModel(snakeModel), snakeView(snakeView), interval(200)
{}

void GameUpdater::run() {
	// Start a timer
	this->timer = new QTimer();
	QObject::connect(this->timer, SIGNAL(timeout()), this, SLOT(updateGame()));
	this->timer->start(this->interval);

	// Start an event loop so that the timer runs
	this->exec();
}

void GameUpdater::updateGame() {
	// Update the snake model
	if (!this->snakeModel->update()) {
		this->qApplication->quit();
	}

	// Update the view to show the udpated model
	this->snakeView->update();
}

void GameUpdater::togglePause() {
	if (this->timer->isActive()) {
		this->timer->stop();
	}

	else {
		this->timer = new QTimer();
		QObject::connect(this->timer, SIGNAL(timeout()), this, SLOT(updateGame()));
		this->timer->start(this->interval);
	}
}

bool GameUpdater::isPaused() {
	return !this->timer->isActive();
}
