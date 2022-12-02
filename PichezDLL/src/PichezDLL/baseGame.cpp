#include "..\..\PichezDLL\baseGame.h" 
#include"..\..\PichezDLL\Timer.h" 
#include "..\..\PichezDLL\CollisionManager.h"
#include "..\..\PichezDLL\Animation.h"

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
	Animation* animation = new Animation();

	static float x;
	static float y;
	static glm::vec2 mousePos;
	window->run();
	shape->createSquare(renderer);
	shape2->createSquare(renderer);
	renderer->renderWindow(window->getWindow()); //Renderizamos la ventana y los objetos dentro de ella (vertices)
	shape2->addPosition(200.0f, 0.0, 0.0f);
	renderer->updateMVPMatrix();
	renderer->updateRendererModelMatrix(shape2->getModelMatrix());

	Texture* texture = new Texture("../res/sauron.png", renderer);
	Texture* texture2 = new Texture("../res/dodge1.png", renderer);
	Texture* texture3 = new Texture("../res/dodge2.png", renderer);
	Texture* texture4 = new Texture("../res/dodge3.png", renderer);
	Texture* texture5 = new Texture("../res/dodge4.png", renderer);
	Texture* texture6 = new Texture("../res/wood.png", renderer);

	animation->AddFrame((float)texture->GetWidth(), (float)texture->GetHeight(), (float)texture->GetWidth(), (float)texture->GetHeight(), (float)texture->GetWidth(), (float)texture->GetHeight(), 0.75f);

	animation->AddFrame(texture2->GetWidth(), texture2->GetHeight(), texture2->GetWidth(), texture2->GetHeight(), texture2->GetWidth(), texture2->GetHeight(), 0.75f);
	animation->AddFrame(texture3->GetWidth(), texture3->GetHeight(), texture3->GetWidth(), texture3->GetHeight(), texture3->GetWidth(), texture3->GetHeight(), 0.75f);
	animation->AddFrame(texture4->GetWidth(), texture4->GetHeight(), texture4->GetWidth(), texture4->GetHeight(), texture4->GetWidth(), texture4->GetHeight(), 0.75f);
	animation->AddFrame(texture5->GetWidth(), texture5->GetHeight(), texture5->GetWidth(), texture5->GetHeight(), texture5->GetWidth(), texture5->GetHeight(), 0.75f);
	//animation->SetCurrentFrame(animation->GetCurrentFrame() + 2, shape->getVertices());


	//UPDATES Y DRAW
	while (!window->windowShouldClose(window->getWindow()))
	{
		renderer->clearWindow();

		renderer->updateViewMatrix();
		renderer->updateRendererModelMatrix(shape->getModelMatrix()); //Se updatea la matriz modelo que usara el renderer, enviamos la matriz de la shape.
		renderer->updateMVPMatrix(); //Updateamos la matriz MVP que utiliza el renderer

		Timer::updateDeltaTime(glfwGetTime());

		animation->Update();
		texture2->Bind(0, animation->GetCurrentFrame());
		shape->draw(renderer, 6, animation->GetCurrentFrame()); //Dibujamos la figura, enviandole que renderer la renderizará y cuantos indices posee
		texture2->Unbind();

		renderer->updateRendererModelMatrix(shape2->getModelMatrix()); //Se updatea la matriz modelo que usara el renderer, enviamos la matriz de la shape.
		renderer->updateMVPMatrix(); //Updateamos la matriz MVP que utiliza el renderer

		texture6->Bind(1, texture6->GetID());
		shape2->draw(renderer, 6, texture6->GetID()); //Dibujamos la figura, enviandole que renderer la renderizará y cuantos indices posee
		texture6->Unbind();
		renderer->swapBuffers(window->getWindow()); //Cambiamos los punteros de los buffers para que apunten a donde corresponda backBuffer to frontBuffer y frontBuffer to backBuffer.
		if (collisionManager->isColliding(shape, shape2))
		{
			std::cout << "Collision";
		}
		window->pollEvents();

		move(window, shape);
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
	delete texture2;
	delete texture3;
	delete texture4;
	delete texture5;
	delete texture6;
	delete texture2;
	delete collisionManager;
	delete animation;

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
