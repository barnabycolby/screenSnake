#ifndef SNAKE_CONTROLLER_H
#define SNAKE_CONTROLLER_H

#include "SnakeModel.h"
#include "GameUpdater.h"

#include <QtWidgets/QWidget>
#include <QtWidgets/QApplication>

class SnakeController : public QWidget {
public:
	SnakeController(QApplication *qApplication, GameUpdater *gameUpdater, SnakeModel *snakeModel);

protected:
	void keyPressEvent(QKeyEvent *event);

private:
	QApplication *qApplication;
	GameUpdater *gameUpdater;
	SnakeModel *snakeModel;
};

#endif
