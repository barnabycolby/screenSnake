#include <QtWidgets/QApplication>

#include "SnakeModel.h"
#include "SnakeView.h"

int main(int argc, char* argv[]) {
	// Initialise the model
	SnakeModel* snakeModel = new SnakeModel();

	// Initialise the view
	QApplication *qApplication = new QApplication(argc, argv);
	SnakeView* snakeView = new SnakeView(snakeModel);

	// Execute the application
	int returnValue = qApplication->exec();

	// Cleanup
	delete snakeView;
	delete snakeModel;
	delete qApplication;

	// Return
	return returnValue;
}
