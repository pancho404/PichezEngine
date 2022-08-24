#include "renderer.h"

DllExport Renderer::Renderer()
{

}

DllExport Renderer::~Renderer()
{

}

DllExport void Renderer::renderWindow(GLFWwindow* window)
{
	while (!windowShouldClose(window))
	{
		clearWindow();

		swapBuffers(window);

		pollEvents();

	}
}

DllExport void Renderer::clearWindow()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

DllExport void Renderer::swapBuffers(GLFWwindow* window)
{
	glfwSwapBuffers(window);
}

DllExport void Renderer::pollEvents()
{
	glfwPollEvents();
}

DllExport int Renderer::windowShouldClose(GLFWwindow* window)
{
	return glfwWindowShouldClose(window);
}
