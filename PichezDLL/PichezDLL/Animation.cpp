#include "Animation.h"
#include"Timer.h"
Animation::Animation()
{

	currentTime = 0;
	currentFrame = 0;
	animationLength = 1000;
	frames = vector<Frame>();
	speed = 1.0f;

}

Animation::~Animation(void)
{

}

void Animation::Update()
{
	currentTime += Timer::getDeltaTime();;

	while (currentTime > animationLength)
	{
		currentTime -= animationLength;
	}

	float frameLength = animationLength / frames.size();
	currentFrame = static_cast<int>(currentTime / frameLength);
}
void Animation::AddFrame(float frameX, float frameY, float frameWidth, float frameHeigth, float textureWidth, float textureHeigth, float durationInSecs)
{
	animationLength = durationInSecs;
	Frame frame;

	frame.uvCoords[0].u = (frameX / textureWidth);
	frame.uvCoords[0].v = (frameY / textureHeigth);

	frame.uvCoords[1].u = ((frameX + frameWidth) / textureWidth);
	frame.uvCoords[1].v = (frameY / textureHeigth);

	frame.uvCoords[2].u = (frameX / textureWidth);
	frame.uvCoords[2].v = ((frameY + frameHeigth) / textureHeigth);

	frame.uvCoords[3].u = ((frameX + frameWidth) / textureWidth);
	frame.uvCoords[3].v = ((frameY + frameHeigth) / textureHeigth);

	this->frames.push_back(frame);
}

void Animation::AddFrame(float frameX, float frameY, float frameWidth, float frameHeigth, float textureWidth, float textureHeigth, float durationInSecs, int frameCount)
{
	animationLength = durationInSecs * 1000;

	float frameXIndex = 0;

	for (int i = 0; i < frameCount; i++)
	{
		Frame frame;

		frame.uvCoords[0].u = ((frameX + frameXIndex) / textureWidth);
		frame.uvCoords[0].v = (frameY / textureHeigth);

		frame.uvCoords[1].u = (((frameX + frameXIndex) + frameWidth) / textureWidth);
		frame.uvCoords[1].v = (frameY / textureHeigth);

		frame.uvCoords[2].u = ((frameX + frameXIndex) / textureWidth);
		frame.uvCoords[2].v = ((frameY + frameHeigth) / textureHeigth);

		frame.uvCoords[3].u = (((frameX + frameXIndex) + frameWidth) / textureWidth);
		frame.uvCoords[3].v = ((frameY + frameHeigth) / textureHeigth);

		frames.push_back(frame);
		frameXIndex += frameWidth;
	}
}

vector<Frame>& Animation::getFrames()
{
	return frames;
}

int Animation::GetCurrentFrame()
{
	return currentFrame + 2;
}

void Animation::SetCurrentFrame(int frame, float* vertex)
{
	{
		Frame f = getFrames()[frame];

		float uvCoords[]
		{
			f.uvCoords[0].u, f.uvCoords[0].v,
			f.uvCoords[1].u, f.uvCoords[1].v,
			f.uvCoords[2].u, f.uvCoords[2].v,
			f.uvCoords[3].u, f.uvCoords[3].v
		};
		vertex[6] = uvCoords[0];
		vertex[14] = uvCoords[2];
		vertex[22] = uvCoords[4];
		vertex[30] = uvCoords[6];

		vertex[7] = uvCoords[1];
		vertex[15] = uvCoords[3];
		vertex[23] = uvCoords[5];
		vertex[31] = uvCoords[7];
	}
}