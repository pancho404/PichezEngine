#include "..\..\PichezDLL\baseGame.h" 

DllExport BaseGame::BaseGame()
{
}

DllExport BaseGame::~BaseGame()
{
}

DllExport int BaseGame::run()
{
	//INIT
	Shape* shape = new Shape();
	Window* window = new Window();
	Renderer* renderer = new Renderer(shape->getModelMatrix());

	//UPDATES Y DRAW
	window->run();
	shape->createSquare();
	shape->setScale(2.0f, 2.0f, 2.0f);
	shape->updateModelMatrix();
	renderer->renderWindow(window->getWindow(), shape->getVertexPositions(), shape->getIndexes());


	while (!window->windowShouldClose(window->getWindow()))
	{
		renderer->clearWindow();

		shape->draw(renderer, 6);

		renderer->swapBuffers(window->getWindow());

		window->pollEvents();
	};

	//DEINIT
	glfwTerminate();
	delete window;
	delete renderer;
	delete shape;
	return 0;

}
