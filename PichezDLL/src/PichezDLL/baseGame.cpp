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
	Renderer* renderer = new Renderer(shape->getModelMatrix(), "ortho");
	window->run();
	shape->createSquare();

	//UPDATES Y DRAW
	while (!window->windowShouldClose(window->getWindow()))
	{
		renderer->clearWindow();
		renderer->renderWindow(window->getWindow(), shape->getVertexPositions(), shape->getIndexes()); //Renderizamos la ventana y los objetos dentro de ella (vertices)

		renderer->updateRendererModelMatrix(shape->getModelMatrix()); //Se updatea la matriz modelo que usara el renderer, enviamos la matriz de la shape.
		renderer->updateMVPMatrix(); //Updateamos la matriz MVP que utiliza el renderer

		shape->addRotationToAxis((float)glfwGetTime(), glm::vec3(1.0f, 0.0f, 0.0f)); // Aplicamos una transformacion a la figura

		shape->draw(renderer, 6); //Dibujamos la figura, enviandole que renderer la renderizará y cuantos indices posee

		renderer->swapBuffers(window->getWindow()); //Cambiamos los punteros de los buffers para que apunten a donde corresponda backBuffer to frontBuffer y frontBuffer to backBuffer.

		window->pollEvents();
	};

	//DEINIT
	glfwTerminate();
	delete window;
	delete renderer;
	delete shape;
	return 0;

}
