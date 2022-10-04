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
	window->run();
	shape->createTriangle();

	//UPDATES Y DRAW
	while (!window->windowShouldClose(window->getWindow()))
	{

		renderer->clearWindow();
		renderer->renderWindow(window->getWindow(), shape->getVertexPositions(), shape->getIndexes());
		renderer->updateRendererModelMatrix(shape->getModelMatrix());

		shape->setRotation((float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));

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
