#pragma once
#include "DLLExport.h"
#include "glew.h"
#include "glfw3.h"
#include "window.h"
#include "renderer.h"
#include "shape.h"
#include"WindowsInput.h"
class BaseGame
{
public:
	DllExport BaseGame();
	DllExport ~BaseGame();
	DllExport int run();

	void move(Window* window, Shape* shape);

private:
	
};

