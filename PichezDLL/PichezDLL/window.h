#pragma once
#include "glfw3.h"

class Window
{
public:
	Window();
	~Window();
	int createWindow();
	GLFWwindow* getWindow();
private:
	GLFWwindow* window;
};
