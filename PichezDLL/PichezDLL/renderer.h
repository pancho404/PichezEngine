#pragma once
#include "glew.h"
#include "glfw3.h"
#include "DLLExport.h"
#include<iostream>
#include<string.h>


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
	DllExport void setBuffers(int quantity, unsigned int& id, unsigned int bufferArray[], GLenum bufferMode);
	DllExport void setFloatVertex();
	DllExport static unsigned int CompileShader(unsigned int type, const std::string& source);
	DllExport static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
private:

};

