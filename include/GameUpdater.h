#ifndef GAME_UPDATER_H
#define GAME_UPDATER_H

#include "SnakeModel.h"
#include "SnakeView.h"

#include <QtWidgets/QApplication>
#include <QtCore/QThread>

class GameUpdater : public QThread {
	Q_OBJECT
public:
	GameUpdater(QApplication *qApplication, SnakeModel *snakeModel, SnakeView *snakeView);

protected:
	void run();

public slots:
	void updateGame();

private:
	QApplication *qApplication;
	SnakeModel *snakeModel;
	SnakeView *snakeView;
};

#endif
