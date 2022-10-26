#pragma once
#include"window.h"
class Input
{
public:
	Input();
	~Input();
	static bool IsKeyPressed(int keycode, Window* window);
	static bool IsMouseButtonPressed(int button, Window* window);
	static glm::vec2 GetMousePosition(Window* window);

	static float GetMouseX(Window* window);
	static float GetMouseY(Window* window);

protected:
	virtual bool IsKeyPressedImp(int keycode, Window* window) = 0;

	virtual bool IsMouseButtonPressedImp(int keycode, Window* window) = 0;
	virtual glm::vec2 GetMousePositionImp(Window* window) = 0;
	virtual float GetMouseXImp(Window* window) = 0;
	virtual float GetMouseYImp(Window* window) = 0;



private:
	static Input* s_Instance;
};
