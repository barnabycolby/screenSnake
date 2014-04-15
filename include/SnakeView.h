#ifndef SNAKE_VIEW_H
#define SNAKE_VIEW_H

#include "SnakeModel.h"

#include <QtWidgets/QWidget>

class SnakeView : public QWidget {
public:
	// Constructor
	SnakeView(const SnakeModel *snakeModel);

protected:
	virtual void paintEvent(QPaintEvent *paintEvent);

private:
	const SnakeModel *model;
};

#endif
