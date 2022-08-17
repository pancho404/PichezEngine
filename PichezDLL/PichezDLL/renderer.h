#pragma once
#include "glfw3.h"
#include "DLLExport.h"

class Renderer
{
public:
	DllExport Renderer();
	DllExport ~Renderer();
	DllExport void renderWindow(GLFWwindow* window);
private:
};

