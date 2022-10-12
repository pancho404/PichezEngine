#include "WindowsInput.h"

Input* Input::s_Instance = new WindowsInput();

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

bool WindowsInput::IsMouseButtonPressedImp(int button, Window* window)
{
	return glfwGetMouseButton(window->getWindow(), button) == GLFW_PRESS;
}

float WindowsInput::GetMouseXImp(Window* window)
{
	double xPos, yPos;

	glfwGetCursorPos(window->getWindow(), &xPos, &yPos);

	return (float)xPos;
}
float WindowsInput::GetMouseYImp(Window* window)
{
	double xPos, yPos;

	glfwGetCursorPos(window->getWindow(), &xPos, &yPos);

	return (float)yPos;
}

std::pair<float, float> WindowsInput::GetMousePositionImp(Window* window)
{
	double xPos, yPos;

	glfwGetCursorPos(window->getWindow(), &xPos, &yPos);

	return { (float)xPos , (float)yPos };
}
