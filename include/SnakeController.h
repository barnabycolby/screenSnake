#ifndef SNAKE_CONTROLLER_H
#define SNAKE_CONTROLLER_H

#include "SnakeModel.h"
#include "GameUpdater.h"

#include <QtWidgets/QWidget>
#include <QtWidgets/QApplication>

class SnakeController : public QWidget {
public:
	SnakeController(QApplication *qApplication, SnakeModel *snakeModel, GameUpdater *gameUpdater);

protected:
	void keyPressEvent(QKeyEvent *event);

private:
	QApplication *qApplication;
	SnakeModel *snakeModel;
	GameUpdater *gameUpdater;
};

#endif
