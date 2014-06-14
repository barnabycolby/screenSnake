#include "GameUpdater.h"

#include <QtCore/QTimer>

GameUpdater::GameUpdater(QApplication *qApplication, SnakeModel *snakeModel, SnakeView *snakeView)
: qApplication(qApplication), snakeModel(snakeModel), snakeView(snakeView)
{}

void GameUpdater::run() {
	// Start a timer
	QTimer *timer = new QTimer();
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(updateGame()));
	timer->start(200);

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
