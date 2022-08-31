#pragma once
#include "glew.h"
#include "glfw3.h"
#include"DLLExport.h"
#include<iostream>

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

private:
	GLFWwindow* window;
};
