#pragma once
class Timer
{
public:
	Timer();
	~Timer();
	static float getDeltaTime();
	static void updateDeltaTime(float currentTime);

private:
	static float currentDeltaTime;
	static float lastDeltaTime;
};

