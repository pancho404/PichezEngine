#pragma once
#include"window.h"
class Input
{
public:
	Input();
	~Input();
	static bool IsKeyPressed(int keycode, Window* window);
	static bool IsMouseButtonPressed(int button, Window* window);
	static std::pair<float,float> GetMousePosition(Window* window);

	static float GetMouseX(Window* window);
	static float GetMouseY(Window* window);

protected:
	virtual bool IsKeyPressedImp(int keycode, Window* window) = 0;

	virtual bool IsMouseButtonPressedImp(int keycode, Window* window) = 0;
	virtual std::pair<float, float> GetMousePositionImp(Window* window) = 0;
	virtual float GetMouseXImp(Window* window) = 0;
	virtual float GetMouseYImp(Window* window) = 0;



private:
	static Input* s_Instance;
};
