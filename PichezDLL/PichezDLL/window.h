#pragma once
#include "glew.h"
#include "glfw3.h"
#include"DLLExport.h"
#include <iostream>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

class Window
{
public:
	DllExport Window();
	DllExport ~Window();
	DllExport int run();
	DllExport GLFWwindow* getWindow();
	DllExport GLFWwindow* createWindow(int width, int height);
	DllExport int init();
	DllExport void terminate();
	DllExport void makeContextCurrent();
	DllExport void pollEvents();
	DllExport int windowShouldClose(GLFWwindow* window);

private:
	GLFWwindow* window;
};
