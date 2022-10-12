#include "Input.h"

Input::Input()
{
}

Input::~Input()
{
}

bool Input::IsKeyPressed(int keycode, Window* window)
{
	return s_Instance->IsKeyPressedImp(keycode, window);
}

bool Input::IsMouseButtonPressed(int button, Window* window)
{
	return s_Instance->IsMouseButtonPressedImp(button, window);
}

std::pair<float, float> Input::GetMousePosition(Window* window)
{
	return s_Instance->GetMousePositionImp(window);
}

float Input::GetMouseX(Window* window)
{
	s_Instance->GetMouseXImp(window);
}

float Input::GetMouseY(Window* window)
{
	return s_Instance->GetMouseYImp(window);
}


