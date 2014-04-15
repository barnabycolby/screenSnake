#ifndef SNAKE_VIEW_H
#define SNAKE_VIEW_H

#include "SnakeModel.h"

#include <QtWidgets/QWidget>

class SnakeView : public QWidget {
public:
	// Constructor
	SnakeView(SnakeModel *snakeModel);

private:
	SnakeModel *model;

protected:
	virtual void paintEvent(QPaintEvent *paintEvent);
};

#endif
