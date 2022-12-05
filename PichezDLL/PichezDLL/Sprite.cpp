#include "Sprite.h"
#include "Sprite.h"
#include "TextureImporter.h"
#include <glew.h>
#include <glfw3.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <iostream>
#include "stb_image.h"
Sprite::Sprite(Renderer* rend) : Entity()
{
	textureVerticesSize = sizeof(vertices);
	texturejeje = NULL;
	vertexBuffer = vertices;
	animation = 0;
	renderer = rend;
	settedAnimation = false;
	lenghtX = 100.0f;
	lenghtY = 100.0f;
}

Sprite::~Sprite()
{
	glDeleteTextures(1, &texture);
	delete texturejeje;
}

void Sprite::LoadTexture(const char* path, bool isTransparent)
{
	if (isAnimation)
	{
		stbi_set_flip_vertically_on_load(true);
	}
	else
	{
		stbi_set_flip_vertically_on_load(false);
	}
	TextureImporter textureImporter;
	this->isTransparent = isTransparent;
	textureImporter.LoadTexture(path, this->data, texture, width, height, channels, isTransparent);
}

void Sprite::StartUseAnimation()
{
	if (!animation)
	{

		animation = new Animation();
	}
}

void Sprite::SetAnimation(int columns, int rows, float framesPerSeconds)
{
	if (animation)
	{
		settedAnimation = true;
		animation->SetAnimationValues(columns, rows, framesPerSeconds, width, height, vertices);
	}
}

void Sprite::AddFrameToAnimation(int frameX, int frameY, int frame, int animationNumber)
{
	if (animation)
	{
		animation->AddFrame(frameX, frameY, frame, animationNumber);
	}
}

void Sprite::DrawTexture(Renderer* renderer)
{
	if (isTransparent)
	{
		BlendSprite();
	}

	//Rebindeo el buffer de UV
	glEnable(GL_TEXTURE_2D);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	renderer->setBuffers(1, vertices, GL_STATIC_DRAW, GL_ARRAY_BUFFER, uvVBO);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
	renderer->drawTexture(6, VAO, VBO, vertices, textureVerticesSize);


	if (isTransparent)
	{
		UnBlendSprite();
	}

}

void Sprite::UpdateAnimation()
{
	if (animation)
	{
		//renderer->setBuffers(1, uvVertices, GL_STATIC_DRAW, GL_ARRAY_BUFFER, uvVerticesBufferObject);
		//glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(6 * sizeof(float))); //Asigna los atributos XYZ RGBA ST del vertice y por cual debera empezar a leer
		//glEnableVertexAttribArray(0);
		animation->UpdateAnimation();
	}
}

float* Sprite::GetVertices()
{
	return vertices;
}

int Sprite::GetChannels()
{
	return channels;
}

void Sprite::BlendSprite()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
void Sprite::UnBlendSprite()
{
	glDisable(GL_BLEND);
}

void Sprite::draw(Renderer* renderer, int indexCount, unsigned int textureID)
{

}

void Sprite::setIsAnimation(bool flag)
{
	isAnimation = flag;
}

void Sprite::AddAnimation()
{
	if (animation)
	{
		animation->CreateAnimation();
	}
}

void Sprite::ChangeAnimation(int animation)
{
	if (this->animation)
	{
		this->animation->ChangeAnimation(animation);
	}
}
