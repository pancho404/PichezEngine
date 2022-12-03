#include "Animation.h"
#include "Timer.h"


Animation::Animation()
{
	animationTextures.clear();
	currentFrame = 0;
	currentTime = 0;
	frameDuration = 0;
}

Animation::~Animation()
{
	animationTextures.clear();
}



void Animation::SetAnimationValues(float framesPerSecond)
{

	frameDuration = 1 / framesPerSecond; //Dividimos 1 segundo por la cantidad de frames

}

void Animation::AddFrame(Texture* texture)
{

	animationTextures.push_back(texture);

}

void Animation::UpdateAnimation()
{

	currentTime += Timer::getDeltaTime();

	if (currentTime >= frameDuration) // si el timer supera la duracion de la animacion...
	{
		while (currentTime > frameDuration)
		{
			currentTime -= frameDuration; //reseteamos timer
			currentFrame++; //seguimos al proximo frame de la animacion y el timer se resetea para que dure lo mismo

			if (currentFrame >= animationTextures.size()) //Si termino la animacion la reseteamos xd
			{
				currentFrame = 0;
			}
		}
	}

}

Texture* Animation::getCurrentFrame()
{
	return animationTextures[currentFrame];
}
