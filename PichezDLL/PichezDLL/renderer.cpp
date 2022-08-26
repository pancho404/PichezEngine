#include "renderer.h"

DllExport Renderer::Renderer()
{

}

DllExport Renderer::~Renderer()
{

}

DllExport void Renderer::renderWindow(GLFWwindow* window)
{
	unsigned int buffer;
	float vertexPositions[vertexBufferSize] =
	{
		-0.5f, -0.5f,
		 0.0f,  0.5f,
		 0.5f, -0.5f
	};
	generateBuffers(1, buffer, vertexBufferSize, vertexPositions, GL_STATIC_DRAW);

	while (!windowShouldClose(window))
	{
		clearWindow();

		glDrawArrays(GL_TRIANGLES, 0, 3);
		
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

//DllExport void createTriangleVertexes()
//{
//	glBegin(GL_TRIANGLES);
//	glVertex2f(-0.5f, -0.5f);
//	glVertex2f( 0.0f, 0.5f);
//	glVertex2f( 0.5f, -0.5f);
//	glEnd();
//	
//}

DllExport void Renderer::generateBuffers(int quantity, unsigned int& id, const int bufferSize, float bufferArray[], GLenum bufferMode)
{
	glGenBuffers(quantity, &id);
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, bufferSize * sizeof(float), bufferArray, bufferMode);
}

