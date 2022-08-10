#include "window.h"


Window::Window()
{
}

Window::~Window()
{

}

GLFWwindow* Window::getWindow()
{
	return window;
}

int Window::createWindow()
{	

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "PichezEngineWindow", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
}
