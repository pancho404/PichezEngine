#pragma once

#include "Texture.h"
#include "Frame.h"
#include <vector>
#define DllExport __declspec( dllexport )

struct UV {
	float U1[32];
	float U2[32];
	float U3[32];
	float U4[32];

	float V1[32];
	float V2[32];
	float V3[32];
	float V4[32];
};
struct Anim {
	UV uv;
	int cantFrames;
};
using namespace std;

class  DllExport Animation
{
private:
	int totalFrames;	

	float timeBetweenFrames;
	float timer;

	int spriteSheetWidth;
	float spriteWidth;
	int spriteSheetHeight;
	float spriteHeight;

	float* spriteVertices;
	int rows;
	int columns;
public:
	int currentFrame;
	Anim animations;
	Animation();
	~Animation();

	void SetAnimationValues(int columns, int rows, float framesPerSecond, int width, int height, float* vertices);
	void AddFrame(int frameX, int frameY, int frame);
	void UpdateAnimation();
	void ChangeFrame();
};

