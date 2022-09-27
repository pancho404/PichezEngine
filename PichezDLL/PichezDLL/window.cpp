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

DllExport GLFWwindow* Window::createWindow(int width, int height)
{
	return glfwCreateWindow(width, height, "PichezEngine", NULL, NULL);
}

DllExport int Window::init()
{
	return glfwInit();
}

DllExport void Window::terminate()
{
	glfwTerminate();
}

DllExport void Window::makeContextCurrent()
{
	glfwMakeContextCurrent(window);
	if (glewInit()!= GLEW_OK)
	{
		std::cout << "Error" << std::endl;
	}	
}

DllExport int Window::run()
{
	if (!init())
		return -1;

	window = createWindow(640, 480);
	if (!window)
	{
		terminate();
		return -1;
	}

	makeContextCurrent();
}

DllExport void Window::pollEvents()
{
	glfwPollEvents();
}


DllExport int Window::windowShouldClose(GLFWwindow* window)
{
	return glfwWindowShouldClose(window);
}

