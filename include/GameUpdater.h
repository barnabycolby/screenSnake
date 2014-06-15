#ifndef GAME_UPDATER_H
#define GAME_UPDATER_H

#include "SnakeModel.h"
#include "SnakeView.h"

#include <QtWidgets/QApplication>
#include <QtCore/QThread>
#include <QtCore/QTimer>

class GameUpdater : public QThread {
	Q_OBJECT
public:
	GameUpdater(QApplication *qApplication, SnakeModel *snakeModel, SnakeView *snakeView);

protected:
	void run();

public slots:
	void updateGame();

public:
	void togglePause();

private:
	QApplication *qApplication;
	SnakeModel *snakeModel;
	SnakeView *snakeView;
	QTimer *timer;
	int interval;
};

#endif
