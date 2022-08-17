#pragma once
#include "glfw3.h"
#include"DLLExport.h"

class Window
{
public:
	DllExport Window();
	DllExport ~Window();
	DllExport int createWindow();
	DllExport GLFWwindow* getWindow();
private:
	GLFWwindow* window;
};
