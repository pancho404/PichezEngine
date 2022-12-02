#pragma once

#include "Frame.h"
#include <vector>
#define DllExport __declspec( dllexport )

using namespace std;
class Animation
{
private:
	float currentFrame;
	float currentTime;
	float animationLength;
	float speed;

public:
	DllExport Animation();
	DllExport ~Animation();

	DllExport void Update();

	DllExport void AddFrame(float frameX, float frameY, float frameWidth, float frameHeigth, float textureWidth, float textureHeigth, float duration);

	DllExport void AddFrame(float frameX, float frameY, float frameWidth, float frameHeigth, float textureWidth, float textureHeigth, float duration, int frameCount);

	DllExport int GetCurrentFrame();

	DllExport vector<Frame>& getFrames();

	DllExport void SetCurrentFrame(int frame, float* vertex);

	vector<Frame> frames;
};

