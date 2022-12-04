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
	Sprite* sprite1 = new Sprite(renderer);
	Sprite* sprite2 = new Sprite(renderer);

	static float x;
	static float y;
	static glm::vec2 mousePos;
	window->run();
	shape->createSquare(renderer);
	shape2->createSquare(renderer);
	renderer->renderWindow(window->getWindow()); //Renderizamos la ventana y los objetos dentro de ella (vertices)
	//shape2->addPosition(200.0f, 0.0, 0.0f);
	sprite2->addPosition(200.0f, 0.0, 0.0f);
	renderer->updateRendererModelMatrix(sprite2->getModelMatrix());
	sprite2->updateModelMatrix();
	renderer->updateMVPMatrix();


	sprite1->LoadTexture("../res/wood.png", true);
	sprite2->LoadTexture("../res/brick.png", true);
	//Texture* texture = new Texture("../res/sauron.png", renderer);
	//Texture* texture2 = new Texture("../res/dodge1.png", renderer);
	//Texture* texture3 = new Texture("../res/dodge2.png", renderer);
	//Texture* texture4 = new Texture("../res/dodge3.png", renderer);
	//Texture* texture5 = new Texture("../res/dodge4.png", renderer);
	//Texture* texture6 = new Texture("../res/wood.png", renderer);
	//Texture* texture7 = new Texture("../res/brick.png", renderer);
	//Texture* texture8 = new Texture("../res/faker.png", renderer);


	//animation->AddFrame()
	//animation->AddFrame(texture2->GetWidth(), texture2->GetHeight(), texture2->GetWidth(), texture2->GetHeight(), texture2->GetWidth(), texture2->GetHeight(), 2.0f, 8);
	//animation->AddFrame(texture3->GetWidth(), texture3->GetHeight(), texture3->GetWidth(), texture3->GetHeight(), texture3->GetWidth(), texture3->GetHeight(), 2.0f, 8);
	//animation->AddFrame(texture->GetWidth(), texture->GetHeight(), texture->GetWidth(), texture->GetHeight(), texture->GetWidth(), texture->GetHeight(), 2.0f, 8);
	//animation->AddFrame(texture->GetWidth(), texture->GetHeight(), texture->GetWidth(), texture->GetHeight(), texture->GetWidth(), texture->GetHeight(), 2.0f, 8);
	//animation->AddFrame(texture->GetWidth(), texture->GetHeight(), texture->GetWidth(), texture->GetHeight(), texture->GetWidth(), texture->GetHeight(), 2.0f, 8);
	//animation->AddFrame(texture4->GetWidth(), texture4->GetHeight(), texture4->GetWidth(), texture4->GetHeight(), texture4->GetWidth(), texture4->GetHeight(), 2.0f, 8);
	//animation->AddFrame(texture5->GetWidth(), texture5->GetHeight(), texture5->GetWidth(), texture5->GetHeight(), texture5->GetWidth(), texture5->GetHeight(), 2.0f, 8);
	//animation->AddFrame(texture6->GetWidth(), texture6->GetHeight(), texture6->GetWidth(), texture6->GetHeight(), texture6->GetWidth(), texture6->GetHeight(), 2.0f, 8);
	//animation->SetCurrentFrame(0, shape->getVertices());

	//animation->AddFrame(texture2);
	//animation->AddFrame(texture3);
	//animation->AddFrame(texture4);
	//animation->AddFrame(texture5);
	//animation->AddFrame(texture);
	//animation->AddFrame(texture6);
	//animation->AddFrame(texture7);
	//animation->AddFrame(texture8);
	//animation->SetAnimationValues(2);

	//UPDATES Y DRAW
	while (!window->windowShouldClose(window->getWindow()))
	{
		renderer->clearWindow();
		Timer::updateDeltaTime(glfwGetTime());

		move(window, sprite1);
		// 
		renderer->updateRendererModelMatrix(sprite1->getModelMatrix()); //Se updatea la matriz modelo que usara el renderer, enviamos la matriz de la shape.
		renderer->updateMVPMatrix(); //Updateamos la matriz MVP que utiliza el renderer
		sprite1->DrawTexture(renderer);


		renderer->updateRendererModelMatrix(sprite2->getModelMatrix()); //Se updatea la matriz modelo que usara el renderer, enviamos la matriz de la shape.
		renderer->updateMVPMatrix(); //Updateamos la matriz MVP que utiliza el renderer
		sprite2->DrawTexture(renderer);

		////animation->UpdateAnimation();
		////animation->getCurrentFrame()->Bind();
		////shape->draw(renderer, 6, animation->getCurrentFrame()->GetID()); //Dibujamos la figura, enviandole que renderer la renderizará y cuantos indices posee
		////animation->getCurrentFrame()->Unbind();
		//renderer->updateRendererModelMatrix(sprite1->getModelMatrix()); //Se updatea la matriz modelo que usara el renderer, enviamos la matriz de la shape.
		//renderer->updateMVPMatrix(); //Updateamos la matriz MVP que utiliza el renderer

		////texture6->Bind();
		////shape2->draw(renderer, 6, texture6->GetID()); //Dibujamos la figura, enviandole que renderer la renderizará y cuantos indices posee
		////texture6->Unbind();

		if (collisionManager->isColliding(sprite1, sprite2))
		{
			std::cout << "Collision";
		}

		x = Input::GetMouseX(window);
		y = Input::GetMouseY(window);
		mousePos = Input::GetMousePosition(window);

		renderer->swapBuffers(window->getWindow()); //Cambiamos los punteros de los buffers para que apunten a donde corresponda backBuffer to frontBuffer y frontBuffer to backBuffer.
		window->pollEvents();
	};

	//DEINIT
	glfwTerminate();
	delete window;
	delete renderer;
	delete shape;
	delete shape2;
	/*delete texture;
	delete texture2;
	delete texture3;
	delete texture4;
	delete texture5;
	delete texture6;
	delete texture2;*/
	delete collisionManager;
	delete animation;

	return 0;

}

void BaseGame::move(Window* window, Entity* entity)
{
	if (glfwGetKey(window->getWindow(), 'D'))
	{
		entity->addPosition(10.0f, 0.0f, 0.0f);
	}
	if (glfwGetKey(window->getWindow(), 'A'))
	{
		entity->addPosition(-10.0f, 0.0f, 0.0f);
	}
	if (glfwGetKey(window->getWindow(), 'Q'))
	{
		entity->addRotationToAxis(-1.5f, glm::vec3(0.0f, 0.0f, 1.0f));
	}
	if (glfwGetKey(window->getWindow(), 'E'))
	{
		entity->addRotationToAxis(1.5f, glm::vec3(0.0f, 0.0f, 1.0f));
	}
	if (glfwGetKey(window->getWindow(), 'S'))
	{
		entity->scaleToRelative(0.9f, 0.9f, 0.9f);
	}
	if (glfwGetKey(window->getWindow(), 'W'))
	{
		entity->scaleToRelative(1.1f, 1.1f, 1.1f);
	}
	if (glfwGetKey(window->getWindow(), GLFW_KEY_DOWN))
	{
		entity->addPosition(0.0f, 10.0f, 0.0f);
	}
	if (glfwGetKey(window->getWindow(), GLFW_KEY_UP))
	{
		entity->addPosition(0.0f, -10.0f, 0.0f);
	}
}
