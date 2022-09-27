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

	renderer->renderWindow(window->getWindow());

	while (!window->windowShouldClose(window->getWindow()))
	{
		renderer->clearWindow();

		shape->draw(renderer); //Dibujamos recorriendo el array indexes ENTERO creado anteriormente

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
