#ifndef SNAKE_VIEW_H
#define SNAKE_VIEW_H

#include "SnakeModel.h"

class SnakeView {
public:
	// Constructor
	SnakeView(const SnakeModel *snakeModel);

private:
	const SnakeModel *model;
};

#endif
