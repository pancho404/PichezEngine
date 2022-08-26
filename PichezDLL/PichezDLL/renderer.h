#pragma once
#include "glew.h"
#include "glfw3.h"
#include "DLLExport.h"

const int vertexBufferSize = 6;

class Renderer
{
public:
	DllExport Renderer();
	DllExport ~Renderer();
	DllExport void renderWindow(GLFWwindow* window);
	DllExport void clearWindow();
	DllExport void swapBuffers(GLFWwindow* window);
	DllExport void pollEvents();
	DllExport int windowShouldClose(GLFWwindow* window);
	//DllExport void createTriangleVertexes();
	DllExport void generateBuffers(int quantity, unsigned int& id, const int bufferSize, float bufferArray[], GLenum bufferMode);
private:
	
};

