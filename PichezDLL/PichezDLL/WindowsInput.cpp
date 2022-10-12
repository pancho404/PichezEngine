#include "WindowsInput.h"

WindowsInput::WindowsInput()
{
}

WindowsInput::~WindowsInput()
{
}

bool WindowsInput::IsKeyPressedImp(int keycode, Window* window)
{
	return glfwGetKey(window->getWindow(), keycode) == GLFW_PRESS || glfwGetKey(window->getWindow(), keycode) == GLFW_REPEAT;
}
