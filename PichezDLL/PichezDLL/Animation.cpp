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
	currentAnimation = 0;
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
}

void Animation::AddFrame(int frameX, int frameY, int frame, int animation)
{
	if (animations.size() >= animation)
	{
		animations[animation].uv.U1[frame] = (spriteWidth * (frameX + 1)) / spriteSheetWidth;
		animations[animation].uv.U2[frame] = (spriteWidth * (frameX + 1)) / spriteSheetWidth;
		animations[animation].uv.U3[frame] = (spriteWidth * frameX) / spriteSheetWidth;
		animations[animation].uv.U4[frame] = (spriteWidth * frameX) / spriteSheetWidth;

		animations[animation].uv.V1[frame] = (spriteHeight / spriteSheetHeight) * frameY;
		animations[animation].uv.V2[frame] = (spriteHeight / spriteSheetHeight) * (frameY - 1);
		animations[animation].uv.V3[frame] = (spriteHeight / spriteSheetHeight) * (frameY - 1);
		animations[animation].uv.V4[frame] = (spriteHeight / spriteSheetHeight) * frameY;
		animations[animation].cantFrames++;
	}	
}

void Animation::ChangeAnimation(int animationToUse)
{
	currentAnimation = animationToUse;
	//currentFrame = 0;
	ChangeFrame();
}

void Animation::CreateAnimation()
{
	Anim anim;
	anim.cantFrames = 0;
	animations.push_back(anim);
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
			if (currentFrame >= animations[currentAnimation].cantFrames)
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
	spriteVertices[6] = animations[currentAnimation].uv.U1[currentFrame];
	spriteVertices[14] = animations[currentAnimation].uv.U2[currentFrame];
	spriteVertices[22] = animations[currentAnimation].uv.U3[currentFrame];
	spriteVertices[30] = animations[currentAnimation].uv.U4[currentFrame];

	spriteVertices[7] = animations[currentAnimation].uv.V1[currentFrame];
	spriteVertices[15] = animations[currentAnimation].uv.V2[currentFrame];
	spriteVertices[23] = animations[currentAnimation].uv.V3[currentFrame];
	spriteVertices[31] = animations[currentAnimation].uv.V4[currentFrame];
}



