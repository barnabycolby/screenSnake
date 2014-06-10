#ifndef GAME_UPDATER_H
#define GAME_UPDATER_H

#include "SnakeModel.h"
#include "SnakeView.h"

#include <QtWidgets/QApplication>
#include <QtCore/QThread>

class GameUpdater : public QThread {
public:
	GameUpdater(QApplication *qApplication, SnakeModel *snakeModel, SnakeView *snakeView);

protected:
	void run();
	void timerEvent(QTimerEvent *event);

private:
	QApplication *qApplication;
	SnakeModel *snakeModel;
	SnakeView *snakeView;
};

#endif
