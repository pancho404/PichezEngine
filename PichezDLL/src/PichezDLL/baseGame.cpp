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

	static float x;
	static float y;
	static glm::vec2 mousePos;
	window->run();
	//shape->createSquare(renderer);
	shape->createSquare(renderer);
	renderer->renderWindow(window->getWindow()); //Renderizamos la ventana y los objetos dentro de ella (vertices)

	Texture* texture = new Texture("../res/sauron.png");
	texture->Bind(0, texture->GetID());
	Texture* texture2 = new Texture("../res/sauron.png");
	texture2->Bind(1, texture2->GetID());

	//UPDATES Y DRAW
	while (!window->windowShouldClose(window->getWindow()))
	{
		renderer->clearWindow();

		renderer->updateRendererModelMatrix(shape->getModelMatrix()); //Se updatea la matriz modelo que usara el renderer, enviamos la matriz de la shape.
		renderer->updateMVPMatrix(); //Updateamos la matriz MVP que utiliza el renderer

		//shape->addRotationToAxis((float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f)); // Aplicamos una transformacion a la figura
		move(window, shape);
		shape->draw(renderer, 6); //Dibujamos la figura, enviandole que renderer la renderizará y cuantos indices posee

		renderer->swapBuffers(window->getWindow()); //Cambiamos los punteros de los buffers para que apunten a donde corresponda backBuffer to frontBuffer y frontBuffer to backBuffer.
		
		window->pollEvents();
		x = Input::GetMouseX(window);
		y = Input::GetMouseY(window);
		mousePos = Input::GetMousePosition(window);
	};

	//DEINIT
	glfwTerminate();
	delete window;
	delete renderer;
	delete shape;
	delete texture;
	return 0;

}

void BaseGame::move(Window* window, Shape* shape)
{
	if (glfwGetKey(window->getWindow(), 'D'))
	{
		shape->addPosition(0.1, 0.0f, 0.0f);
	}
	if (glfwGetKey(window->getWindow(), 'A'))
	{
		shape->addPosition(-0.1, 0.0f, 0.0f);
	}
	if (glfwGetKey(window->getWindow(), 'Q'))
	{
		shape->addRotationToAxis(1.5f, glm::vec3(0.0f, 0.0f, 1.0f));
	}
	if (glfwGetKey(window->getWindow(), 'E'))
	{
		shape->addRotationToAxis(-1.5f, glm::vec3(0.0f, 0.0f, 1.0f));
	}
	if (glfwGetKey(window->getWindow(), 'S'))
	{
		shape->scaleToRelative(0.9f, 0.9f, 0.9f);
	}
	if (glfwGetKey(window->getWindow(), 'W'))
	{
		shape->scaleToRelative(1.1f, 1.1f, 1.1f);
	}
}
