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

	// Draw background
	painter.drawRect(0, 0, this->width(), this->height());

	// Draw grid
	int screenWidth = this->width();
	int screenHeight = this->height();
	float squareWidthExact = (float)screenWidth / (float)this->model->getGridWidth();
	float squareHeightExact = (float)screenHeight / (float)this->model->getGridHeight();
	int squareWidth = (squareWidthExact * 0.8);
	int squareHeight = (squareHeightExact * 0.8);
	vector<vector<SquareType>*> *squares = this->model->getGrid();
	for (int i = 0; i < this->model->getGridHeight(); i++) {
		for (int j = 0; j < this->model->getGridWidth(); j++) {
			// Set the colour based on the square
			if (squares->at(i)->at(j) != EMPTY) {
				if (squares->at(i)->at(j) == SNAKE) {
					painter.setBrush(QColor(255, 0, 0, 255));
				}
				else if (squares->at(i)->at(j) == FOOD) {
					painter.setBrush(QColor(0, 255, 0, 255));
				}

				// Draw the square
				int x = (j * squareWidthExact) + (squareWidthExact * 0.1);
				int y = (i * squareHeightExact) + (squareHeightExact * 0.1);
				painter.drawRect(x, y, squareWidth, squareHeight);
			}
		}
	}
}
