#include "..\..\PichezDLL\baseGame.h" 
#include"..\..\PichezDLL\Timer.h" 
#include "..\..\PichezDLL\CollisionManager.h"

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
	Shape* shape2 = new Shape();
	Window* window = new Window();
	Renderer* renderer = new Renderer(shape->getModelMatrix(), "ortho");
	CollisionManager* collisionManager = new CollisionManager();

	static float x;
	static float y;
	static glm::vec2 mousePos;
	window->run();
	shape->createSquare(renderer);
	shape2->createTriangle(renderer);
	renderer->renderWindow(window->getWindow()); //Renderizamos la ventana y los objetos dentro de ella (vertices)
	shape2->addPosition(200.0f, 0.0, 0.0f);
	renderer->updateMVPMatrix();
	renderer->updateRendererModelMatrix(shape2->getModelMatrix());

	Texture* texture = new Texture("../res/sauron.png");
	texture->Bind(1, texture->GetID());
	Texture* texture2 = new Texture("../res/wood.png");
	

	//UPDATES Y DRAW
	while (!window->windowShouldClose(window->getWindow()))
	{
		renderer->clearWindow();

		//renderer->updateViewMatrix();
		renderer->updateRendererModelMatrix(shape->getModelMatrix()); //Se updatea la matriz modelo que usara el renderer, enviamos la matriz de la shape.
		renderer->updateMVPMatrix(); //Updateamos la matriz MVP que utiliza el renderer
		Timer::updateDeltaTime(glfwGetTime());

		move(window, shape);

		shape->draw(renderer, 6); //Dibujamos la figura, enviandole que renderer la renderizará y cuantos indices posee

		//move(window, shape2);

		renderer->updateRendererModelMatrix(shape2->getModelMatrix()); //Se updatea la matriz modelo que usara el renderer, enviamos la matriz de la shape.
		renderer->updateMVPMatrix(); //Updateamos la matriz MVP que utiliza el renderer

		shape2->draw(renderer, 3); //Dibujamos la figura, enviandole que renderer la renderizará y cuantos indices posee
		
		renderer->swapBuffers(window->getWindow()); //Cambiamos los punteros de los buffers para que apunten a donde corresponda backBuffer to frontBuffer y frontBuffer to backBuffer.

		if (collisionManager->isColliding(shape, shape2))
		{
			texture2->Bind(2, texture2->GetID());
			texture->Unbind();
			std::cout << "Collision";
		}

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
	delete shape2;
	delete texture;
	delete collisionManager;
	return 0;

}

void BaseGame::move(Window* window, Shape* shape)
{
	if (glfwGetKey(window->getWindow(), 'D'))
	{
		shape->addPosition(10.0f, 0.0f, 0.0f);
	}
	if (glfwGetKey(window->getWindow(), 'A'))
	{
		shape->addPosition(-10.0f, 0.0f, 0.0f);
	}
	if (glfwGetKey(window->getWindow(), 'Q'))
	{
		shape->addRotationToAxis(-1.5f, glm::vec3(0.0f, 0.0f, 1.0f));
	}
	if (glfwGetKey(window->getWindow(), 'E'))
	{
		shape->addRotationToAxis(1.5f, glm::vec3(0.0f, 0.0f, 1.0f));
	}
	if (glfwGetKey(window->getWindow(), 'S'))
	{
		shape->scaleToRelative(0.9f, 0.9f, 0.9f);
	}
	if (glfwGetKey(window->getWindow(), 'W'))
	{
		shape->scaleToRelative(1.1f, 1.1f, 1.1f);
	}
	if (glfwGetKey(window->getWindow(), GLFW_KEY_DOWN))
	{
		shape->addPosition(0.0f, 10.0f, 0.0f);
	}
	if (glfwGetKey(window->getWindow(), GLFW_KEY_UP))
	{
		shape->addPosition(0.0f, -10.0f, 0.0f);
	}
}
