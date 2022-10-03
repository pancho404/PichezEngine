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
	Window* window = new Window();
	Renderer* renderer = new Renderer();
	Shape* shape = new Shape();

	//UPDATES Y DRAW
	window->run();
	shape->createSquare();
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
