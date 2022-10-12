#include "Input.h"

bool Input::IsKeyPressed(int keycode)
{
	return s_Instance->IsKeyPressedImp(keycode);
}
