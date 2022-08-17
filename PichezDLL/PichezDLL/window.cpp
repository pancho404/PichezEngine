#include "window.h"


DllExport Window::Window()
{
}

DllExport Window::~Window()
{

}

DllExport GLFWwindow* Window::getWindow()
{
	return window;
}

DllExport int Window::createWindow()
{	
	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(640, 480, "PichezEngineWindow", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
}
