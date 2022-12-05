#include "Animation.h"
#include "Timer.h"


Animation::Animation()
{
	currentFrame = 0;
	totalFrames = 0;
	timePerFrame = 0;
	currentTIme = 0;
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
	timePerFrame = 1 / framesPerSecond; //Calculamos cuando dura cada frame dividiendo 1 segundo por los frames que hay por segundo
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
	ChangeFrame(); //Llamamos a ChangeFrame para darles nuevas coordenadas de Uv a la animacion
}

void Animation::CreateAnimation()
{
	Anim anim;
	anim.cantFrames = 0; //inicializo en 0 para poder pushbackear
	animations.push_back(anim); //Añado una animacion a el vector de animaciones, el size aumenta
}



void Animation::UpdateAnimation()
{
	currentTIme += Timer::getDeltaTime(); 

	while (currentTIme > timePerFrame)
	{
		currentTIme -= timePerFrame;
		currentFrame++; //Pasamos al frame siguiente
		if (currentFrame >= animations[currentAnimation].cantFrames) //si se va fuera del vector de animaciones o llega al final de la animacion entonces reseteamos la animacion
		{
			currentFrame = 0;
		}
	}
	ChangeFrame();

}

void Animation::ChangeFrame()
{
	spriteVertices[6] = animations[currentAnimation].uv.U1[currentFrame]; //Segun la animacion actual, actualizamos la primera coordenada de UV correspondiente al frame actual;
	spriteVertices[14] = animations[currentAnimation].uv.U2[currentFrame];
	spriteVertices[22] = animations[currentAnimation].uv.U3[currentFrame];
	spriteVertices[30] = animations[currentAnimation].uv.U4[currentFrame];

	spriteVertices[7] = animations[currentAnimation].uv.V1[currentFrame];
	spriteVertices[15] = animations[currentAnimation].uv.V2[currentFrame];
	spriteVertices[23] = animations[currentAnimation].uv.V3[currentFrame];
	spriteVertices[31] = animations[currentAnimation].uv.V4[currentFrame];
}



