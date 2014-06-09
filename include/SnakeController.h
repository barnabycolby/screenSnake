#ifndef SNAKE_CONTROLLER_H
#define SNAKE_CONTROLLER_H

#include "SnakeModel.h"

#include <QtWidgets/QWidget>

class SnakeController : public QWidget {
public:
	SnakeController(SnakeModel *snakeModel);

protected:
	void keyPressEvent(QKeyEvent *event);

private:
	SnakeModel *snakeModel;
};

#endif
