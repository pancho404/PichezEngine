#pragma once
#include"Input.h"

class WindowsInput : public Input
{
public:
	WindowsInput();
	~WindowsInput();

protected:
	virtual bool IsKeyPressedImp(int keycode, Window* window) override;
private:

};
