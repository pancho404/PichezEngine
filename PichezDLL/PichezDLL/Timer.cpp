#include "Timer.h"

Timer::Timer()
{
}

Timer::~Timer()
{
}

float Timer::getDeltaTime()
{
	return currentDeltaTime;
}

void Timer::updateDeltaTime(float currentTime)
{
	currentDeltaTime = currentTime - lastDeltaTime;
	lastDeltaTime = currentTime;
}
float Timer::currentDeltaTime = 0;
float Timer::lastDeltaTime = 0;