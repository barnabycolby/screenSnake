#include "SnakeModel.h"

#include "SnakeView.h"

#include <QtGui/QPainter>

SnakeView::SnakeView(const SnakeModel *snakeModel)
: QWidget(0), model(snakeModel)
{
	this->setAttribute(Qt::WA_TranslucentBackground);
	this->showFullScreen();
}

void SnakeView::paintEvent(QPaintEvent *) {
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setPen(Qt::NoPen);
	painter.setBrush(QColor(200, 200, 200, 200));

	painter.drawRect(0, 0, this->width(), this->height());
}
