#include "..\..\PichezDLL\baseGame.h" 

DllExport BaseGame::BaseGame()
{
}

DllExport BaseGame::~BaseGame()
{
}

DllExport int BaseGame::run()
{
	Window* window = new Window();
	Renderer* renderer = new Renderer();

	window->run();

	renderer->renderWindow(window->getWindow());

	glfwTerminate();
	delete window;
	delete renderer;
	return 0;
}
