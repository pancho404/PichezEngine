#include "Sprite.h"
#include "Sprite.h"
#include "TextureImporter.h"
#include <glew.h>
#include <glfw3.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <iostream>

Sprite::Sprite(Renderer* rend) : Entity()
{
	textureVerticesSize = sizeof(vertices);
	texturejeje = NULL;
	vertexBuffer = vertices;
	animation = NULL;
	renderer = rend;
	settedAnimation = false;
}

Sprite::~Sprite()
{
	glDeleteTextures(1, &texture);
	delete texturejeje;
}

void Sprite::LoadTexture(const char* path, bool isTransparent)
{
	TextureImporter textureImporter;
	this->isTransparent = isTransparent;
	textureImporter.LoadTexture(path, this->data, texture, width, height, channels, isTransparent);
	//texturejeje = new Texture(path, renderer);

}

void Sprite::StartUseAnimation()
{
}

void Sprite::SetAnimation(int columns, int rows, float framesPerSeconds)
{
}

void Sprite::AddFrameToAnimation(int frameX, int frameY, int frame)
{
}

void Sprite::DrawTexture(Renderer* renderer)
{
	if (isTransparent)
	{
		BlendSprite();
	}

	glBindTexture(GL_TEXTURE_2D, texture);

	renderer->Draw(6, VAO, texture);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, 0);

	if (isTransparent)
	{
		UnBlendSprite();
	}
	//unsigned int vao2 = getVAO();
	//texturejeje->Bind();
	//renderer->Draw(sizeof(indices), vao2, texturejeje->GetID());
	//texturejeje->Unbind();
	
}

void Sprite::UpdateAnimation()
{
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
