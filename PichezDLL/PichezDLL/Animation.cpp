#include "Animation.h"
#include "Timer.h"


Animation::Animation()
{
	currentFrame = 0;
	totalFrames = 0;
	timeBetweenFrames = 0;
	timer = 0;
	spriteSheetWidth = 0;
	spriteWidth = 0;
	spriteSheetHeight = 0;
	spriteHeight = 0;
	spriteVertices = 0;
}

Animation::~Animation()
{

}

void Animation::SetAnimationValues(int columns, int rows, float framesPerSecond, int width, int height, float* vertices)
{
	timeBetweenFrames = 1.0f / framesPerSecond;
	this->rows = rows;
	this->columns = columns;

	spriteSheetWidth = width;
	spriteSheetHeight = height;
	spriteVertices = vertices;

	spriteWidth = spriteSheetWidth / columns;
	spriteHeight = spriteSheetHeight / rows;
	animations.cantFrames = 0;
}

void Animation::AddFrame(int frameX, int frameY, int frame)
{
	animations.uv.U1[frame] = (spriteWidth * (frameX + 1)) / spriteSheetWidth;
	animations.uv.U2[frame] = (spriteWidth * (frameX + 1)) / spriteSheetWidth;
	animations.uv.U3[frame] = (spriteWidth * frameX) / spriteSheetWidth;
	animations.uv.U4[frame] = (spriteWidth * frameX) / spriteSheetWidth;
	
	animations.uv.V1[frame] = (spriteHeight / spriteSheetHeight) * frameY;
	animations.uv.V2[frame] = (spriteHeight / spriteSheetHeight) * (frameY - 1);
	animations.uv.V3[frame] = (spriteHeight / spriteSheetHeight) * (frameY - 1);
	animations.uv.V4[frame] = (spriteHeight / spriteSheetHeight) * frameY;
	animations.cantFrames++;
}

void Animation::UpdateAnimation()
{
	timer += Timer::getDeltaTime();

	if (timer >= timeBetweenFrames) 
	{
		while (timer > timeBetweenFrames)
		{
			timer -= timeBetweenFrames;
			currentFrame++;
			if (currentFrame >= animations.cantFrames)
			{
				currentFrame = 0;
			}
		}
		ChangeFrame();
		timer += Timer::getDeltaTime();
	}
}

void Animation::ChangeFrame()
{
	spriteVertices[6] = animations.uv.U1[currentFrame];
	spriteVertices[14] = animations.uv.U2[currentFrame];
	spriteVertices[22] = animations.uv.U3[currentFrame];
	spriteVertices[30] = animations.uv.U4[currentFrame];

	spriteVertices[7] = animations.uv.V1[currentFrame];
	spriteVertices[15] = animations.uv.V2[currentFrame];
	spriteVertices[23] = animations.uv.V3[currentFrame];
	spriteVertices[31] = animations.uv.V4[currentFrame];
}



