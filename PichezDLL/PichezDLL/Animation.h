#pragma once

#include "Texture.h"
#include "Frame.h"
#include <vector>
#define DllExport __declspec( dllexport )

using namespace std;

class  DllExport Animation
{
private:
	int currentFrame;
	float currentTime;
	float frameDuration;
	vector<Texture*> animationTextures;
public:
	Animation();
	~Animation();

	void SetAnimationValues(float framesPerSecond);
	void AddFrame(Texture* texture);
	void UpdateAnimation();
	void ChangeFrame();
	void Draw();
	Texture* getCurrentFrame();
	vector<Frame> frames;
};

