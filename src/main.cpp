#include <QtWidgets/QApplication>

#include "SnakeModel.h"
#include "SnakeView.h"
#include "SnakeController.h"
#include "GameUpdater.h"

int main(int argc, char* argv[]) {
	// Initialise the model
	SnakeModel* snakeModel = new SnakeModel();

	// Initialise the view
	QApplication *qApplication = new QApplication(argc, argv);
	SnakeView *snakeView = new SnakeView(snakeModel);

	// Start a thread to udpate the model on a timer
	GameUpdater *gameUpdater = new GameUpdater(qApplication, snakeModel, snakeView);
	gameUpdater->start();

	// Start a thread to receive key events and update the model
	SnakeController *snakeController = new SnakeController(snakeModel);

	// Execute the application
	int returnValue = qApplication->exec();

	// Cleanup
	delete snakeView;
	delete gameUpdater;
	delete snakeController;
	delete snakeModel;
	delete qApplication;

	// Return
	return returnValue;
}
