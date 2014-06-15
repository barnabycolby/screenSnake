#include "SnakeModel.h"

#include <QtGui/QPainter>
#include <vector>
#include <iostream>

#include "SnakeView.h"
#include "model/Square.h"

using namespace std;

SnakeView::SnakeView(SnakeModel *snakeModel)
: QWidget(0), model(snakeModel)
{
	this->setAttribute(Qt::WA_TranslucentBackground);
	this->showFullScreen();
}

void SnakeView::paintEvent(QPaintEvent *) {
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setPen(Qt::NoPen);
	painter.setBrush(QColor(200, 200, 200, 100));

	// Draw grid
	int screenWidth = this->width();
	int screenHeight = this->height();
	float squareWidthExact = (float)screenWidth / (float)this->model->getGridWidth();
	float squareHeightExact = (float)screenHeight / (float)this->model->getGridHeight();
	int squareWidth = (squareWidthExact * 0.8);
	int squareHeight = (squareHeightExact * 0.8);

	vector<Square*> *squares = this->model->getOccupiedSquares();
	for (Square *square : *squares) {
		SquareType type = square->getType();
		if (type == SNAKE) {
			painter.setBrush(QColor(255, 0, 0, 150));
		}
		else if (type == FOOD) {
			painter.setBrush(QColor(0, 255, 0, 150));
		}

		// Draw the square
		int x = (square->getX() * squareWidthExact) + (squareWidthExact * 0.1);
		int y = (square->getY() * squareHeightExact) + (squareHeightExact * 0.1);
		painter.drawRect(x, y, squareWidth, squareHeight);
	}

	delete squares;
}
