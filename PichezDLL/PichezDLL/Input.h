#pragma once
#include"window.h"
class Input
{
public:
	Input();
	~Input();
	static bool IsKeyPressed(int keycode);

protected:
	virtual bool IsKeyPressedImp(int keycode, Window* window) = 0;


private:
	static Input* s_Instance;
};
