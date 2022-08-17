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

DllExport GLFWwindow* Window::createWindow(int width, int height, std::string name)
{
	return glfwCreateWindow(width, height, "name", NULL, NULL);
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
	return glfwMakeContextCurrent(window);
}

DllExport int Window::run()
{
	if (!init())
		return -1;

	window = createWindow(640, 480, "PichezEngineWindow");
	if (!window)
	{
		terminate();
		return -1;
	}

	makeContextCurrent();
}
