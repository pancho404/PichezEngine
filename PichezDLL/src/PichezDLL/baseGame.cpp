#include "../include/glfw3.h"
#include "..\..\PichezDLL\baseGame.h"
#include "../../PichezDLL/window.h"

int main()
{
	BaseGame* game = new BaseGame();
	game->run();
	delete game;
}

BaseGame::BaseGame()
{
}

BaseGame::~BaseGame()
{
}

int BaseGame::run()
{
	Window* window = new Window();
	////GLFWwindow* window;

	///* Initialize the library */
	//if (!glfwInit())
	//	return -1;

	///* Create a windowed mode window and its OpenGL context */
	//window = glfwCreateWindow(640, 480, "PichezEngineWindow", NULL, NULL);
	//if (!window)
	//{
	//	glfwTerminate();
	//	return -1;
	//}

	///* Make the window's context current */
	//glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	window->createWindow();

	while (!glfwWindowShouldClose(window->getWindow()))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glfwSwapBuffers(window->getWindow());

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}
