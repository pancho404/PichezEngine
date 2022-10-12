#pragma once
#include"Input.h"

class WindowsInput : public Input
{
public:
	WindowsInput();
	~WindowsInput();

protected:
	virtual bool IsKeyPressedImp(int keycode, Window* window) override;
	virtual bool IsMouseButtonPressedImp(int button, Window* window)override;

	virtual float GetMouseXImp(Window* window)override;
	virtual float GetMouseYImp(Window* window)override;
	virtual std::pair<float, float> GetMousePositionImp(Window* window);
private:

};
